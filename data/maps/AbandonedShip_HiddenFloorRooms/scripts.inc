AbandonedShip_HiddenFloorRooms_MapScripts::
	.byte 0

@ After the below calculation, VAR_TEMP_4 is the room number of the door the player entered
@ Bottom row, left column   (Rm 1)
@ Bottom row, middle column (Rm 2)
@ Bottom row, right column	(Rm 3)
@ Upper row,  left column   (Rm 4)
@ Upper row,  middle column (Rm 5)
@ Upper row,  right column  (Rm 6)

AbandonedShip_HiddenFloorRooms_EventScript_Trash::
	lockall
	msgbox AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_HiddenFloorRooms_Text_BrightShinyTrash:
	.string "It's bright and shiny!\n"
	.string "But it's just trash…$"

