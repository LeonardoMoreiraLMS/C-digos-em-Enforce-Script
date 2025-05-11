modded class MissionServer
{
    override void OnEvent(EventType eventTypeId, Param params)
    {
        super.OnEvent(eventTypeId, params);

        if (eventTypeId == ChatMessageEventTypeID)
        {
            ChatMessageEventParams chatParams = ChatMessageEventParams.Cast(params);
            PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

            if (chatParams.text == "/fix")
            {
                CarScript car = CarScript.Cast(player.GetParent());

                if (car)
                {
                    car.SetHealth("", "", 100);
                    car.Fill(CarFluid.FUEL, 100);
                    car.Fill(CarFluid.COOLANT, 100);
                    car.Fill(CarFluid.OIL, 100);
                    car.Fill(CarFluid.BRAKE, 100);

                    Param1<string> msg = new Param1<string>("✅ Veículo reparado com sucesso!");
                    GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, msg, true, player.GetIdentity());
                }
            }
        }
    }
}
