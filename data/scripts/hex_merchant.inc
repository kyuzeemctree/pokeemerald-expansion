EventScript_HexMerchant::
	lock
	faceplayer
	playbgm MUS_B_PIKE, TRUE
	call_if_unset FLAG_HEXMERCHANT_INTRO, EventScript_HexMerchant_Intro
	goto EventScript_HexMerchant_Shop
	end

EventScript_HexMerchant_Shop::
	message Text_HexMerchant_Sell
	waitmessage
	pokemart Pokemart_HexMerchant
	applymovement LOCALID_HEX_MERCHANT, Movement_HexMerchant_Spin
	waitmovement 0
	playse SE_THUNDER
	msgbox Text_HexMerchant_Bye, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	waitmovement 0
	release
	end

	.align 2
Pokemart_HexMerchant:
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_GOOD_ROD
	.2byte ITEM_FLY_TOOL
	.2byte ITEM_CUT_TOOL
	.2byte ITEM_ROCKSMASH_TOOL
	.2byte ITEM_DOWSING_MACHINE
	.2byte ITEM_SUPER_ROD
	.2byte ITEM_SURF_TOOL
	.2byte ITEM_DIVE_TOOL
	.2byte ITEM_MEGA_RING
	.2byte ITEM_STRENGTH_TOOL
	.2byte ITEM_WATERFALL_TOOL
	.2byte ITEM_NONE
	release
	end

EventScript_HexMerchant_Intro::
	setflag FLAG_HEXMERCHANT_INTRO
	msgbox Text_HexMerchant_Intro, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

EventScript_Poko::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	msgbox Route104_MrBrineysHouse_Text_Poko, MSGBOX_DEFAULT
	waitmoncry
	applymovement LOCALID_POKO, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	release
	end

Movement_HexMerchant_Spin:
	face_up
	delay_1
	face_left
	delay_1
	face_down
	delay_1
	face_right
	delay_1
	face_up
	delay_1
	face_left
	delay_1
	face_down
	delay_1
	face_right
	delay_1
	face_up
	delay_1
	face_left
	delay_1
	face_down
	delay_1
	step_end

Text_HexMerchant_Intro:
	.string "Hm? You're {PLAYER}{KUN}…\n"
	.string "I had seen visions of your\l"
	.string "arrival…\p"
	.string "What's that?\n"
	.string "How was I able to perceive\l"
	.string "your identity?\p"
	.string "Perhaps it's best I don't\n"
	.string "tell you…\p"
	.string "More importantly!\n"
	.string "I am the Hex Merchant…\p"
	.string "I sell various mysterious wares that\n"
	.string "will no doubt expand your options\l"
	.string "as well as your mind…\p"
	.string "You may find me out across\n"
	.string "the region. Talk to me\l"
	.string "again if you're interested…$"

Text_HexMerchant_Sell:
	.string "Well, well, well…\n"
	.string "Care to browse the wares?$"

Text_HexMerchant_Bye:
	.string "I APPRECIATE YOUR PATRONAGE!$"

Route104_MrBrineysHouse_Text_Poko:
	.string "POKO: Brrrrhu!$"
