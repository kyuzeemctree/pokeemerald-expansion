@ NOTE: Route 104's sail to Dewford script references local IDs from Dewford's map.
@  These are labeled in DewfordTown/scripts.inc
.set LOCALID_HEXM, 29
.set LOCALID_POKO, 30

Route104_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
	.byte 0

Route104_OnTransition:
	call Route104_EventScript_ShowOrHideWhiteHerbFlorist
	end

Route104_EventScript_ShowOrHideWhiteHerbFlorist::
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_HideWhiteHerbFlorist
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_HideWhiteHerbFlorist
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return

Route104_EventScript_HideWhiteHerbFlorist::
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return

EventScript_BattleWingull::
	lock
	faceplayer
	playmoncry SPECIES_WINGULL, CRY_MODE_ENCOUNTER
	delay 16
	waitmoncry
	setwildbattle SPECIES_WINGULL, 15
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, EventScript_RemoveWingull
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, EventScript_RemoveWingull
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, EventScript_RemoveWingull
	release
	end

EventScript_RemoveWingull::
	goto Common_EventScript_RemoveStaticPokemon
	end

Route104_EventScript_ExpertF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_ReceivedBerry
	msgbox Route104_Text_PlantBerriesInSoilTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_CHESTO_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_ReceivedBerry::
	msgbox Route104_Text_TrainersOftenMakeMonHoldBerries, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_WhiteHerbFlorist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_ReceivedWhiteHerb
	msgbox Route104_Text_DontNeedThisTakeIt, MSGBOX_DEFAULT
	giveitem ITEM_WHITE_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_WHITE_HERB
	release
	end

Route104_EventScript_ReceivedWhiteHerb::
	msgbox Route104_Text_FlowerShopSellingSaplings, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Girl1::
	msgbox Route104_Text_BrineyLivesInSeasideCottage, MSGBOX_NPC
	end

Route104_EventScript_BugCatcher::
	msgbox Route104_Text_WhatsItLikeAtBottomOfSea, MSGBOX_SIGN
	end

Route104_EventScript_BrineysCottageSign::
	msgbox Route104_Text_MrBrineysCottage, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignPetalburg::
	msgbox Route104_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignPetalburgW::
	msgbox Route104_Text_RouteSignPetalburgW, MSGBOX_SIGN
	end

Route104_EventScript_RouteSignRustboro::
	msgbox Route104_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route104_EventScript_FlowerShopSign::
	msgbox Route104_Text_PrettyPetalFlowShop, MSGBOX_SIGN
	end

Route104_EventScript_TrainerTipsDoubleBattles::
	msgbox Route104_Text_TrainerTipsDoubleBattles, MSGBOX_SIGN
	end

Route104_EventScript_Boy1::
	msgbox Route104_Text_ThrowBallAtWeakenedPokemon, MSGBOX_NPC
	end

Route104_EventScript_Woman::
	msgbox Route104_Text_OnlyThrowBallAtWildPokemon, MSGBOX_NPC
	end

Route104_EventScript_Boy2::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SEED_BOMB, Route104_EventScript_ReceivedBulletSeed
	msgbox Route104_Text_LikeFillingMouthWithSeedsTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SEED_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SEED_BOMB
	release
	end

Route104_EventScript_ReceivedBulletSeed::
	msgbox Route104_Text_TMsAreOneTimeUse, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Girl2::
	msgbox Route104_Text_ImNotATrainer, MSGBOX_NPC
	end

Route104_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY, Route104_Text_BillyIntro, Route104_Text_BillyDefeat
	msgbox Route104_Text_BillyPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Haley::
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_HaleyIntro, Route104_Text_HaleyDefeat, Route104_EventScript_TryRegisterHaleyAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchHaley
	setvar VAR_0x8004, TRAINER_HALEY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterHaley
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_TryRegisterHaleyAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaleyAfterBattle
	release
	end

Route104_EventScript_RegisterHaleyAfterBattle::
	msgbox Route104_Text_HaleyRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_TryRegisterHaley::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterHaley
	msgbox Route104_Text_HaleyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterHaley::
	msgbox Route104_Text_HaleyRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_RematchHaley::
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_HaleyRematchIntro, Route104_Text_HaleyRematchDefeat
	msgbox Route104_Text_HaleyPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Winston::
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_WinstonIntro, Route104_Text_WinstonDefeat, Route104_EventScript_TryRegisterWinstonAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchWinston
	setvar VAR_0x8004, TRAINER_WINSTON_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterWinston
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_TryRegisterWinstonAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinstonAfterBattle
	release
	end

Route104_EventScript_RegisterWinstonAfterBattle::
	msgbox Route104_Text_WinstonRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_TryRegisterWinston::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterWinston
	msgbox Route104_Text_WinstonPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterWinston::
	msgbox Route104_Text_WinstonRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_RematchWinston::
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_WinstonRematchIntro, Route104_Text_WinstonRematchDefeat
	msgbox Route104_Text_WinstonPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Cindy::
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_CindyIntro, Route104_Text_CindyDefeat, Route104_EventScript_TryRegisterCindyAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route104_EventScript_RematchCindy
	setvar VAR_0x8004, TRAINER_CINDY_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route104_EventScript_TryRegisterCindy
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_TryRegisterCindyAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindyAfterBattle
	release
	end

Route104_EventScript_RegisterCindyAfterBattle::
	msgbox Route104_Text_CindyRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end

Route104_EventScript_TryRegisterCindy::
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_RegisterCindy
	msgbox Route104_Text_CindyPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_RegisterCindy::
	msgbox Route104_Text_CindyRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end

Route104_EventScript_RematchCindy::
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_CindyRematchIntro, Route104_Text_CindyRematchDefeat
	msgbox Route104_Text_CindyPostRematch, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_Gina::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Mia::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_Darian::
	trainerbattle_single TRAINER_DARIAN, Route104_Text_DarianIntro, Route104_Text_DarianDefeat
	msgbox Route104_Text_DarianPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_Text_BrineyLivesInSeasideCottage:
	.string "That seaside cottage is where\n"
	.string "Mr. Briney lives.\p"
	.string "He was once a mighty sailor who never\n"
	.string "feared the sea, however stormy.$"

Route104_Text_WhatsItLikeAtBottomOfSea:
	.string "The sea, huh?\p"
	.string "I wonder what it's like at the bottom\n"
	.string "of the sea?$"

Route104_Text_ThrowBallAtWeakenedPokemon: @ 81ED6A2
	.string "If you're going to throw a pokéball,\n"
	.string "weaken the wild pokémon first.\p"
	.string "It will be easier to catch if it's been\n"
	.string "poisoned, burned, or lulled to sleep.$"

Route104_Text_OnlyThrowBallAtWildPokemon:
	.string "You're a thief if you try to steal\n"
	.string "someone else's pokémon.\p"
	.string "You should throw Poké Balls only at\n"
	.string "wild pokémon.$"

Route104_Text_ImNotATrainer: @ 81ED7A2
	.string "Oh, no, I'm not a Trainer.\p"
	.string "But that's right, if Trainers lock eyes,\n"
	.string "it's a challenge to battle.\p"
	.string "If you don't want to battle, stay out\n"
	.string "of their sight.$"

Route104_Text_LikeFillingMouthWithSeedsTakeThis:
	.string "I like filling my mouth with seeds,\n"
	.string "then spitting them out fast!\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a pokémon, and it will learn\n"
	.string "a move for firing seeds rapidly.$"

Route104_Text_TMsAreOneTimeUse:
	.string "A word of advice!\p"
	.string "A TM, Technical Machine, is good only\n"
	.string "for one-time use.\p"
	.string "Once you use it, it's gone.\n"
	.string "Think twice before using it!$"

Route104_Text_DontNeedThisTakeIt: @ 81ED96A
	.string "This Flower Shop started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping.\p"
	.string "I don't need this White Herb anymore.\n"
	.string "Would you take it, please?$"

Route104_Text_FlowerShopSellingSaplings: @ 81EDA0F
	.string "This Flower Shop started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"

Route104_Text_MrBrineysCottage: @ 81EDA8C
	.string "Mr. Briney's Cottage$"

Route104_Text_RouteSignPetalburg: @ 81EDAA1
	.string "Route 1O4\n"
	.string "{RIGHT_ARROW} Petalburg City$"

Route104_Text_RouteSignRustboro: @ 81EDABC
	.string "Route 1O4\n"
	.string "{UP_ARROW} Rustboro City$"

Route104_Text_RouteSignPetalburgW:
	.string "Caution:\n"
	.string "{UP_ARROW} Petalburg Woods$"

Route104_Text_PrettyPetalFlowShop: @ 81EDAD6
	.string "Pretty Petal Flower Shop$"

Route104_Text_TrainerTipsDoubleBattles: @ 81EDAEF
	.string "Trainer Tips\p"
	.string "In the Hoenn region there are pairs\n"
	.string "of Trainers who challenge others\l"
	.string "for 2-on-2 pokémon battles called\l"
	.string "Double Battles.\p"
	.string "In a Double Battle, the Trainer must\n"
	.string "send out two pokémon, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how pokémon are lined up.$"

Route104_Text_MayWeShouldRegister: @ 81EDBFF
	.string "May: Oh, hi, {PLAYER}{KUN}!\p"
	.string "Devon upgraded your Pokénav with\n"
	.string "the Match Call system, huh?\p"
	.string "We should register each other so we\n"
	.string "can get in contact anytime.$"

Route104_Text_RegisteredMay: @ 81EDC8F
	.string "{PLAYER} registered May\n"
	.string "in the Pokénav.$"

Route104_Text_MayHowsYourPokedex: @ 81EDCB1
	.string "May: Oh, by the way, {PLAYER}{KUN},\n"
	.string "how's your Pokédex coming along?$"

Route104_Text_MayMinesDecentLetsBattle:
	.string "Mine's looking pretty decent.\n"
	.string "So…\l"
	.string "How about a little battle?$"

Route104_Text_MayHaventRaisedPokemon: @ 81EDD2A
	.string "May: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "pokémon very much?\p"
	.string "That's not very good for a Trainer!$"

Route104_Text_MayLetsBattle: @ 81EDD9F
	.string "May: So, what do you think?\n"
	.string "How about a little battle here?$"

Route104_Text_MayIntro: @ 81EDDDB
	.string "May: You just became a Trainer,\n"
	.string "{PLAYER}{KUN}. I'm not going to lose!$"

Route104_Text_MayDefeat:
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route104_Text_MayPostBattle: @ 81EDE3E
	.string "May: I can tell you've gotten pretty\n"
	.string "good with the way you handle pokémon.\p"
	.string "But instead of only making them\n"
	.string "battle, you should be like Mr. Briney.\p"
	.string "It's important to become friends with\n"
	.string "pokémon, too.$"

Route104_Text_BrendanWeShouldRegister: @ 81EDF04
	.string "Brendan: Oh, hey, {PLAYER}!\p"
	.string "Cool, you had Devon install the Match\n"
	.string "Call system on your Pokénav!\p"
	.string "Let's register each other in our\n"
	.string "Pokénavs so we can keep in touch.$"

Route104_Text_RegisteredBrendan: @ 81EDFA0
	.string "{PLAYER} registered Brendan\n"
	.string "in the Pokénav.$"

Route104_Text_BrendanHowsYourPokedex: @ 81EDFC6
	.string "Brendan: {PLAYER}, how's your Pokédex?\n"
	.string "Have you filled in any pages yet?$"

Route104_Text_BrendanDoingGreatLetsBattle:
	.string "Me, I'm doing great!\p"
	.string "Want to check out how good I am with\n"
	.string "a battle?$"

Route104_Text_BrendanNoConfidence: @ 81EE04D
	.string "Brendan: What's the matter? Don't have\n"
	.string "any confidence in your pokémon?$"

Route104_Text_BrendanLetsBattle: @ 81EE094
	.string "Brendan: What's up?\n"
	.string "Want to have a battle with me?$"

Route104_Text_BrendanIntro: @ 81EE0C7
	.string "Brendan: I know you just became\n"
	.string "a Trainer, but I won't go easy!$"

Route104_Text_BrendanDefeat:
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route104_Text_BrendanPostBattle: @ 81EE120
	.string "Brendan: You've gotten pretty decent\n"
	.string "at handling pokémon.\p"
	.string "But, you know, you shouldn't just be\n"
	.string "making pokémon battle.\p"
	.string "Like Mr. Briney, it's important to\n"
	.string "become friends with your pokémon.$"
