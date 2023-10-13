EventScript_UseSurf::
@ Start qol_field_moves
	//checkpartymove MOVE_SURF
    checkitem ITEM_SURF_TOOL, 1
    goto_if_eq VAR_RESULT, TRUE, EventScript_UseSurfTool
@ End qol_field_moves
EventScript_UseSurfMove:: @ qol_field_moves
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end
