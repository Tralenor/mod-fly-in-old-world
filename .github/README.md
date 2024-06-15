# Short Overview (for AzerothCore-Catalouge)

* Name: mod-fly-in-old-world
* What it does: This Module allows to control which players can fly in the old world (Eastern Kingdom + Kalimdor)

## How to use the mod-fly-in-old-world for Azerothcore
If you want to allow all players to fly in the old world, just stop after the first step, follow-up steps only limit who can fly:
* edit the client AreaTable DBC to allow flight in all old world areas
* provide a spell (default Spell ID is 200001) which players can learn Ingame (this is done to mimic the behaviour of Cold Weather flight for Northrend, in Fact the easiest way to achieve this is to copy the spell Cold Weather Flying(SpellID 54197))
* install the module
  * in case you picked a different SpellId in the step above go into the SourceCode and adjust the SpellId.
