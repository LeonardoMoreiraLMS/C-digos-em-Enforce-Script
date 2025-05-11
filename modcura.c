modded class MissionServer
{
    override void OnEvent(EventType eventTypeId, Param params)
    {
        super.OnEvent(eventTypeId, params);

        if (eventTypeId == ChatMessageEventTypeID)
        {
            ChatMessageEventParams chatParams = ChatMessageEventParams.Cast(params);
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

            if (chatParams.text == "/heal")
            {
                player.SetHealth("", "", 100);
                player.GetStatEnergy().Set(4000);
                player.GetStatWater().Set(4000);

                Param1<string> msg = new Param1<string>("🩹 Você foi curado e está alimentado.");
                GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, msg, true, player.GetIdentity());
            }
        }
    }
}
