--[DESCRIPTION]
--The script does the following actions:
--1) Imports .OBJ
--2) Resets Material 01
--3) Applies Material 01 to imported obj
--4) Applies black wireframe colour
--5) Converts to Editable Poly
--6) Applies single smoothing group (SM 1) to the entire model

--[CREDIT}
--No single person can take full credit for the script.Its is generally a collection 
--of two scripts found on Polycount.com and my simple complilation/editing. 
--The contributors are RenderHjs(renderhjs.net) and Slum(floatvoid.com/blog/)

--------------------------------------------------------------------------
macroscript Import_Obj
Category:  "Butt tools" buttonText: "Import OBJ"
(
	filename = OpenFileName
	path = getOpenFileName "Select .OBJ" \
	types:"WaveFront Object(*.OBJ)|*.*|"
	file_url = filename
	--RENDERHJS'S CUSTOM SCRIPT HELP
	importFile (path) #noPrompt
	disableSceneRedraw()
	--HELP FROM VIG
	meditMaterials[1] = Standardmaterial ()
	$.material= meditmaterials[1]
	$.wirecolor = color 0 0 0
	ConvertTo $ Editable_Poly
	--SLUMS SCRIPT (SMOOTHTASTIC)
	$.EditablePoly.SetSelection #Face #{1..$.numfaces}      --select all faces
	$.EditablePoly.setSmoothingGroups 1 1 1     --assign selection to smooth group 1 
	enableSceneRedraw()
	completeRedraw()
	
)
