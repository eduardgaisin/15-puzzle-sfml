add_custom_target( unZip ALL ) 
add_custom_command(
	TARGET unZip
	COMMAND ${CMAKE_COMMAND} -E tar xzf
		${CMAKE_SOURCE_DIR}/font/font.zip
	DEPENDS 
		${CMAKE_SOURCE_DIR}/font/font.zip
	WORKING_DIRECTORY 
		${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/
	COMMENT "Unpacking font.zip"
	VERBATIM
)