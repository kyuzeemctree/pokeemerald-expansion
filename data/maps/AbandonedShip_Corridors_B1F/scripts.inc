AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	end

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro: @ 8237E2A
	.string "When we go out to sea, we Sailors\n"
	.string "always bring our pokémon.\l"
	.string "How about a quick battle?$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
	.string "Whoops, I'm sunk!$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
	.string "The ship's bottom has sunk into the\n"
	.string "depths.\p"
	.string "If a pokémon knew how to go underwater,\n"
	.string "we might make some progress…$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip:
	.string "Yay!\n"
	.string "It's a ship!$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
	.string "The door is locked.\p"
	.string "“Storage” is painted on the door.$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
	.string "{PLAYER} inserted and turned the\n"
	.string "Storage Key.\p"
	.string "The inserted Key stuck fast,\n"
	.string "but the door opened.$"

AbandonedShip_Text_TheDoorIsOpen:
	.string "The door is open.$"

