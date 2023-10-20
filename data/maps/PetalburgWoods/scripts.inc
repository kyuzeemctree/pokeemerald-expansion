.set LOCALID_RIVAL, 6

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

PetalburgWoods_EventScript_RivalLeft::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PetalburgWoods_EventScript_RivalMayLeft
	goto_if_eq VAR_RESULT, FEMALE, PetalburgWoods_EventScript_RivalBrendanLeft
	end

PetalburgWoods_EventScript_RivalRight::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, PetalburgWoods_EventScript_RivalMayRight
	goto_if_eq VAR_RESULT, FEMALE, PetalburgWoods_EventScript_RivalBrendanRight
	end

PetalburgWoods_EventScript_RivalMayLeft::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
    applymovement LOCALID_RIVAL, PetalburgWoods_Movement_RivalApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_MayLetsBattle, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, PetalburgWoods_Text_MayDefeated
	msgbox PetalburgWoods_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
    closemessage
	goto PetalburgWoods_EventScript_RivalExitLeft
	end

PetalburgWoods_EventScript_RivalBrendanLeft::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
    applymovement LOCALID_RIVAL, PetalburgWoods_Movement_RivalApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, PetalburgWoods_Text_BrendanDefeated
	msgbox PetalburgWoods_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
    closemessage
	goto PetalburgWoods_EventScript_RivalExitLeft
	end

PetalburgWoods_EventScript_RivalMayRight::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
    applymovement LOCALID_RIVAL, PetalburgWoods_Movement_RivalApproachPlayerRight
	waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_MayLetsBattle, MSGBOX_DEFAULT
    trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, PetalburgWoods_Text_MayDefeated
    msgbox PetalburgWoods_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
    closemessage
    goto PetalburgWoods_EventScript_RivalExitRight
	end

PetalburgWoods_EventScript_RivalBrendanRight::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
    applymovement LOCALID_RIVAL, PetalburgWoods_Movement_RivalApproachPlayerRight
	waitmovement 0
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, PetalburgWoods_Text_BrendanDefeated
    msgbox PetalburgWoods_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
    closemessage
    goto PetalburgWoods_EventScript_RivalExitRight
	end

PetalburgWoods_EventScript_RivalExitLeft::
	applymovement LOCALID_RIVAL, PetalburgWoods_Movement_RivalExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RivalEnd
	end

PetalburgWoods_EventScript_RivalExitRight::
	applymovement LOCALID_RIVAL, PetalburgWoods_Movement_RivalExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RivalEnd
	end

PetalburgWoods_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_PETALBURG_WOODS_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

PetalburgWoods_Movement_RivalExitLeft:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
    walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgWoods_Movement_RivalApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_RivalApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_RivalExitRight:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
    walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgWoods_Movement_WatchRivalLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_EARTH_POWER, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_TM_EARTH_POWER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_EARTH_POWER
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_MayLetsBattle:
	.string "Oh hey! I know you! You're the Gym\n"
	.string "Leader's kid, {PLAYER}{KUN}!\p"
	.string "My Dad called me and told me you were\n"
	.string "coming this direction.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a TRAINER is like.$"

PetalburgWoods_Text_MayDefeated:
	.string "Wow! That's great!\n"
	.string "{PLAYER}{KUN}, you're pretty good!$"

PetalburgWoods_Text_MayTimeToHeadBack:
	.string "MAY: I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that POKéMON,\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of POKéMON easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the LAB.$"

PetalburgWoods_Text_BrendanLetsBattle:
	.string "Oh hey! I know you! You're the Gym\n"
	.string "Leader's kid, {PLAYER}{KUN}!\p"
	.string "My Dad called me and told me you were\n"
	.string "coming this direction.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a TRAINER's\n"
	.string "about!$"

PetalburgWoods_Text_BrendanDefeated:
	.string "Huh, {PLAYER}, you're not too shabby.$"

PetalburgWoods_Text_BrendanTimeToHeadBack:
	.string "BRENDAN: I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your POKéMON already likes you,\n"
	.string "even though you just got it.\p"
	.string "{PLAYER}, I get the feeling that you\n"
	.string "could befriend any POKéMON with ease.\p"
	.string "Well, I should head back to the LAB.$"

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Not a one to be found…$"

PetalburgWoods_Text_HaveYouSeenShroomish: @ 822E34F
	.string "Hello, have you seen any pokémon\n"
	.string "called Shroomish around here?\p"
	.string "I really love that pokémon.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in Petalburg Woods\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"

PetalburgWoods_Text_HandOverThosePapers: @ 822E428
	.string "You! Devon Researcher!\p"
	.string "Hand over those papers!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh!\p"
	.string "You're a pokémon trainer, aren't you?\n"
	.string "You've got to help me, please!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hunh? What do you think you're doing?\n"
	.string "What, you're going to protect him?\p"
	.string "No one who crosses Team Aqua\n"
	.string "gets any mercy, not even a kid!\p"
	.string "Come on and battle me!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "You're kidding me! You're tough!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… You've got some nerve\n"
	.string "meddling with Team Aqua!\l"
	.string "Come on and battle me again!\p"
	.string "I wish I could say that, but I'm out of\n"
	.string "pokémon…\p"
	.string "And, hey, we of Team Aqua are also\n"
	.string "after something in Rustboro.\p"
	.string "I'll let you go today!$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a Great Ball as\n"
	.string "my thanks!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro: @ 822E6C7
	.string "Didn't that Team Aqua thug say\n"
	.string "they were after something in\l"
	.string "Rustboro, too?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "You're loaded with items.\n"
	.string "I can't give you this Great Ball.$"

PetalburgWoods_Text_GoBugPokemonTeam: @ 822E77D
	.string "I caught a whole bunch of pokémon!\p"
	.string "Go, go, go!\n"
	.string "My bug pokémon team!$"

PetalburgWoods_Text_ICouldntWin: @ 822E7C1
	.string "I have all these pokémon,\n"
	.string "but I couldn't win…$"

PetalburgWoods_Text_ImOutOfPokeBalls: @ 822E7EF
	.string "I caught a bunch of pokémon.\n"
	.string "Now I'm out of pokéballs.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon: @ 822E827
	.string "If you take bug pokémon to school,\n"
	.string "you get to be instantly popular!$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_PeopleRespectYou: @ 822E889
	.string "If you have a big bug pokémon,\n"
	.string "people respect you for it.$"

PetalburgWoods_Text_IWantRematch1: @ 822E8C3
	.string "I want a rematch when my bug\n"
	.string "pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_IWantRematch2: @ 822E914
	.string "I want a rematch when my bug \n"
	.string "pokémon grow up!\p"
	.string "I'm registering you in my Pokénav!$"

PetalburgWoods_Text_MyPokemonHaveGrown: @ 822E966
	.string "My bug pokémon have grown.\n"
	.string "I'll be popular again.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "I can't be popular if I lose.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "You get to be popular if you have\n"
	.string "strong pokémon, right?\l"
	.string "So, I've been training hard.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, there!\n"
	.string "Your pokémon doing okay?\p"
	.string "If your pokémon are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, wow!\n"
	.string "You look like a rookie trainer!\p"
	.string "You should try using this item.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "It's the TM for Earth Power.\n"
	.string "It's a strong ground type move\l"
	.string "which is good against rock types.\p"
	.string "Don't worry about repaying me. I\n"
	.string "was a rookie too once. I know it\l"
	.string "can be rough starting out.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "Trainer Tips\p"
	.string "If you own an EXP Share, it can be\n"
	.string "switched on or off.\p"
	.string "To raise a weak POKéMON, simply\n"
	.string "turn on the EXP Share.\p"
	.string "This will allow it to gain experience\n"
	.string "without being exposed to any harm.$"

PetalburgWoods_Text_TrainerTipsPP: @ 822ED07
	.string "Trainer Tips\p"
	.string "In addition to Hit Points (HP), pokémon\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a pokémon runs out of PP, it must be\n"
	.string "taken to a Pokémon Center.$"

