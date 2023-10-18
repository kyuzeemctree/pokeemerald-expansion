.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	.byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lock
	faceplayer
	call_if_lt VAR_DEVON_CORP_3F_STATE, 1, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterGreet
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGreet MSGBOX_DEFAULT
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterGreet::
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneAfterGreet MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	call_if_lt VAR_DEVON_CORP_3F_STATE, 1, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterGreet
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGreet MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneGreet:
	.string "I'm MR. STONE, the PRESIDENT of\n"
	.string "the DEVON CORPORATION.\p"
	.string "I'm impressed by the amount of\n"
	.string "guts it must take to just walk into\l"
	.string "the top floor of a corporation!\p"
	.string "Lucky for you, I like a person with\n"
	.string "some guts.$"

RustboroCity_DevonCorp_3F_Text_MrStoneAfterGreet:
	.string "Lucky for you, I like a person with\n"
	.string "some guts.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "MR. STONE: Now, you should know that\n"
	.string "I am a great PRESIDENT.\p"
	.string "So, I'd never be so cheap as to ask\n"
	.string "a favor for nothing in return.\p"
	.string "That's why I want you to have this!$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} received a POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. STONE: That device…\p"
	.string "It's a POKéMON NAVIGATOR, or POKéNAV\n"
	.string "for short.\p"
	.string "It's an indispensable tool for any\n"
	.string "TRAINER on an adventure.\p"
	.string "It has a map of the HOENN region.\p"
	.string "You can check the locations of\n"
	.string "DEWFORD and SLATEPORT easily!\p"
	.string "By the way, I've heard that sinister\n"
	.string "criminals--MAGMA and AQUA, I believe--\l"
	.string "have been making trouble far and wide.\p"
	.string "I think it would be best if you rested\n"
	.string "up before you go on your way.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "MR. STONE: Well, then, {PLAYER}{KUN},\n"
	.string "go with caution and care!$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "MR. STONE: I'm counting on you!$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "MR. STONE: You delivered my LETTER?\n"
	.string "Thank you kindly!\p"
	.string "This is my way of thanking you.\n"
	.string "It should help you, a TRAINER.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "MR. STONE: A POKéMON holding that\n"
	.string "EXP. SHARE will be given some of the\l"
	.string "EXP Points from battle.\p"
	.string "It will get EXP Points even if it didn't\n"
	.string "actually battle.\p"
	.string "I would say EXP. SHARE is quite useful\n"
	.string "for raising weak POKéMON.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "MR. STONE: Since my youth, I've immersed\n"
	.string "myself in work.\p"
	.string "Consequently, I'm not familiar with\n"
	.string "trends and that sort of thing.\p"
	.string "But do young people all want to be\n"
	.string "TRAINERS in the POKéMON LEAGUE?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "This is the DEVON CORPORATION's\n"
	.string "third floor.\p"
	.string "Our PRESIDENT's OFFICE is on\n"
	.string "this floor.\p"
	.string "Anyway, I can't tell you how much I'm\n"
	.string "grateful for what you've done.\p"
	.string "Um… By the way, that parcel\n"
	.string "you got back for us…\p"
	.string "Could I get you to deliver that to\n"
	.string "the SHIPYARD in SLATEPORT?\p"
	.string "It would be awful if those robbers\n"
	.string "tried to take it again.\p"
	.string "Uh… Hehehe, so, uh, could I count\n"
	.string "on you to do that for me?\p"
	.string "Oh, that's right.\n"
	.string "Could you wait here a second?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Our PRESIDENT would like to have\n"
	.string "a word with you.\p"
	.string "Please come with me.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Please, go ahead.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "If you visit the SHIPYARD in SLATEPORT,\n"
	.string "you should go see CAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "DEVON's new products, the REPEAT BALL\n"
	.string "and TIMER BALL, have become hugely\l"
	.string "popular among TRAINERS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "It's a collection of rare rocks and\n"
	.string "stones assembled by the PRESIDENT.$"

