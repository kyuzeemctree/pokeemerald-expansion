IslandCave_MapScripts::
	.byte 0

IslandCave_OnResume:
	end

IslandCave_EventScript_TryRemoveRegice::
	return

IslandCave_OnLoad:
	end

IslandCave_EventScript_HideRegiEntrance::
	return

IslandCave_OnTransition:
	end

IslandCave_EventScript_ShowRegice::
	return

IslandCave_EventScript_OpenRegiEntrance::
	end

IslandCave_EventScript_CaveEntranceMiddle::
	end

IslandCave_EventScript_BigHoleInWall::
	end

IslandCave_EventScript_CaveEntranceSide::
	end

IslandCave_EventScript_CloseBrailleMsg::
	end

IslandCave_EventScript_ClearSteps::
	return

IslandCave_EventScript_Regice::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGICE, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, IslandCave_EventScript_DefeatedRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, IslandCave_EventScript_RanFromRegice
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, IslandCave_EventScript_RanFromRegice
	setflag FLAG_DEFEATED_REGICE
	release
	end

IslandCave_EventScript_DefeatedRegice::
	setflag FLAG_DEFEATED_REGICE
	goto Common_EventScript_RemoveStaticPokemon
	end

IslandCave_EventScript_RanFromRegice::
	setvar VAR_0x8004, SPECIES_REGICE
	goto Common_EventScript_LegendaryFlewAway
	end
