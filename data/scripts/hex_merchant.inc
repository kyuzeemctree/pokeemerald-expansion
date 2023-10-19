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
	msgbox Text_HexMerchant_Bye, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	applymovement LOCALID_HEXM, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	release
	end

	.align 2
Pokemart_HexMerchant:
	.2byte ITEM_EXP_CANDY_S
	.2byte ITEM_EXP_CANDY_M
	.2byte ITEM_EXP_CANDY_L
	.2byte ITEM_ABILITY_PATCH
	.2byte ITEM_FLY_TOOL
	.2byte ITEM_CUT_TOOL
	.2byte ITEM_ROCKSMASH_TOOL
	.2byte ITEM_SURF_TOOL
	.2byte ITEM_DIVE_TOOL
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

Text_HexMerchant_Intro:
	.string "Hm? You're {PLAYER}{KUN}…\n"
	.string "I had seen visions of your\l"
	.string "arrival…\p"
	.string "What's that?\n"
	.string "How was I able to perceive\l"
	.string "your identity?\p"
	.string "Perhaps it's best I don't\n"
	.string "tell you…\p"
	.string "More importantly!\p"
	.string "I am the Hex Merchant…\n"
	.string "I sell various mysterious wares that\n"
	.string "will no doubt expand your options\l"
	.string "as well as your mind…\p"
	.string "You may find me out across\n"
	.string "the region. Talk to me again"\l"
	.string "if you're interested.$"

Text_HexMerchant_Sell:
	.string "Well, well, well…\n"
	.string "Care to browse the wares?$"

Text_HexMerchant_Bye:
	.string "Take care now…$"

Route104_MrBrineysHouse_Text_Poko:
	.string "POKO: Brrrrhu!$"
