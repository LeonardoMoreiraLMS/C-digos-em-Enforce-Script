modded class PlayerBase
{
    override void OnConnect()
    {
        super.OnConnect();

        if (GetIdentity() && !GetGame().IsServer()) return;

        if (!IsInventoryInitialized())
        {
            InventoryLocation loc = new InventoryLocation();
            EntityAI item;

            item = GetInventory().CreateInInventory("M4A1");
            if (item) item.GetInventory().CreateAttachment("ACOGOptic");

            GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
            GetInventory().CreateInInventory("NBCJacketGray");
            GetInventory().CreateInInventory("NBCPantsGray");
            GetInventory().CreateInInventory("CombatBoots_Black");
            GetInventory().CreateInInventory("Canteen");

            Print("🎁 Kit inicial entregue!");
        }
    }
}
