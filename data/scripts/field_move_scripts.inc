@ Interact with cuttable tree
EventScript_CutTree::
	lockall
@ Start qol_field_moves
	//checkpartymove MOVE_CUT
    checkitem ITEM_CUT_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_CutTreeDown
@ End qol_field_moves
	goto EventScript_CheckTreeCantCut
	end

@ Use cut from party menu
EventScript_UseCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
    setflag FLAG_SYS_USE_CUT @ qol_field_moves
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	waitstate
	releaseall
	end

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!\p"
	.string "Would you like to Cut it?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!$"

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
@ Start qol_field_moves
	//checkpartymove MOVE_ROCK_SMASH
    checkitem ITEM_ROCKSMASH_TOOL,1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseRockSmashTool
@ End qol_field_moves
	goto_if_eq VAR_RESULT, FALSE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_SmashRock
	end

EventScript_SmashRock::
    setflag FLAG_SYS_USE_ROCK_SMASH @ qol_field_moves
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special RockSmashWildEncounter
	waitstate
	releaseall
	end

EventScript_EndSmash::
	releaseall
	end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use Rock Smash?$"

Text_CantSmash: @ 829087F
	.string "It's a rugged rock, but a pokémon\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
@ Start qol_field_moves
	//checkpartymove MOVE_STRENGTH
    checkitem ITEM_STRENGTH_TOOL,1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseStrengthTool
@ End qol_field_moves
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end

EventScript_UseStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
    call_if_set FLAG_SYS_USE_STRENGTH, EventScript_PushBoulderScript @ qol_field_moves
	goto EventScript_ActivateStrength
	end

EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	releaseall
	end

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
    buffermovename STR_VAR_2, MOVE_STRENGTH @ qol_field_moves
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength: @ 829092C
	.string "It's a big boulder, but a pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use Strength?$"

Text_MonUsedStrength: @ 829098C
	.string "{STR_VAR_1} used Strength!\p"
	.string "{STR_VAR_1}'s Strength made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength: @ 82909D6
	.string "It's a big boulder, but a pokémon\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated: @ 8290A16
	.string "Strength made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall::
	lockall
@ Start qol_field_moves
	//checkpartymove MOVE_WATERFALL
    checkitem ITEM_WATERFALL_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseWaterfallTool
@ End qol_field_moves
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantWaterfall
	setfieldeffectargument 0, VAR_RESULT
@ Start qol_field_moves
EventScript_UseWaterfallMon::
    setflag FLAG_SYS_USE_WATERFALL
@ End qol_field_moves
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CannotUseWaterfall::
	lockall

EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT

EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use Waterfall?$"

Text_MonUsedWaterfall: @ 8290AFC
	.string "{STR_VAR_1} used Waterfall.$"

EventScript_UseDive::
	lockall
@ Start qol_field_moves
	//checkpartymove MOVE_DIVE
    call EventScript_CheckDiveToolAndParty
@ End qol_field_moves
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseDiveUnderwater::
	lockall
@ Start qol_field_moves
	//checkpartymove MOVE_DIVE
    call EventScript_CheckDiveToolAndParty
@ End qol_field_moves
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	releaseall
	end

Text_CantDive: @ 8290BAA
	.string "The sea is deep here. A pokémon\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use Dive?$"

Text_MonUsedDive: @ 8290C1A
	.string "{STR_VAR_1} used Dive.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A pokémon may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use Dive?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"
