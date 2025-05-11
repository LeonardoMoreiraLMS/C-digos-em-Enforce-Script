modded class MissionServer
{
    override void OnClientReady(PlayerBase player, DayZPlayerIdentity identity)
    {
        super.OnClientReady(player, identity);

        if (player && identity)
        {
            string name = identity.GetName();
            string msg = "🟢 Bem-vindo ao servidor, " + name + "!";

            Param1<string> m = new Param1<string>(msg);
            GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m, true, player.GetIdentity());
        }
    }
}
