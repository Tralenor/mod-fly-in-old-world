/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU AGPL v3 license: https://github.com/azerothcore/azerothcore-wotlk/blob/master/LICENSE-AGPL3
 */

#include "ScriptMgr.h"
#include "Player.h"

enum {
    OLD_WORLD_FLYING_SPELL = 200001
};

// Add player scripts
class FlyInOldWorld : public PlayerScript
{
public:
    FlyInOldWorld() : PlayerScript("FlyInOldWorld") { }

    bool OnCanPlayerFlyInZone(Player* player, uint32 mapId, uint32 zoneId, SpellInfo const* bySpell) override
    {
        player->GetSession()->SendAreaTriggerMessage("%s", "Hook executed");
        uint32 v_map = GetVirtualMapForMapAndZone(mapId, zoneId);
        if (v_map == 0 || v_map == 1)
        {
            player->GetSession()->SendAreaTriggerMessage("%s", "Hook in vMap = 0/1");
            if (!player->HasSpell(OLD_WORLD_FLYING_SPELL)) // 54197 = Cold Weather Flying
            {
                player->GetSession()->SendAreaTriggerMessage("%s", "Hook: has no Spell");
                return false;
            }
            
        }
        player->GetSession()->SendAreaTriggerMessage("%s", "Hook: end reached - return true");
        return true;
    }
};

// Add all scripts in one
void AddFlyInOldWorld()
{
    new FlyInOldWorld();
}
