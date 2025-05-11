modded class MissionServer
{
    override void OnEvent(EventType eventTypeId, Param params)
    {
        super.OnEvent(eventTypeId, params);

        if (eventTypeId == ChatMessageEventTypeID)
        {
            ChatMessageEventParams chatParams = ChatMessageEventParams.Cast(params);
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

            if (chatParams.text == "/tpbase")
            {
                vector basePos = "5000 0 5000"; // Coordenadas da base
                vector surf = GetGame().SurfaceY(basePos[0], basePos[2]);
                basePos[1] = surf + 0.5;

                player.SetPosition(basePos);

                Param1<string> msg = new Param1<string>("📍 Teleportado para a base.");
                GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, msg, true, player.GetIdentity());
            }
        }
    }
}
