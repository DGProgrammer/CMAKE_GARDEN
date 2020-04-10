cmake_minimum_required (VERSION 3.0) #Version minima de cmake
project(Garden) #Nombre del proyecto --> ${PROJECT_NAME}
set(CMAKE_CXX_STANDARD 11) #Lenguaje y version que esta usando

include_directories(src/public) #Busca los archivos donde tendremos los include
file(GLOB_RECURSE SRC_CORE src/private/*.cpp) #Busca todos los archivos acabados como ponga 
# GLOB_RECURSE significa que lo hace de manera recursiva

add_executable (${PROJECT_NAME} ${SRC_CORE} src/main.cpp) #Crea el ejecutable Nombre + todos los archivos a añadir
find_package(SFML 2.5 COMPONENTS REQUIRED network audio graphics window system) #Busca las librerias NombreFind(SFML) + Version(2.5) + 
																				#COMPONENTS REQUIRED(Si falla los archivos no compila) 

target_link_libraries( #Nombre de las libs
	${PROJECT_NAME}
	opengl32 sfml-network sfml-audio sfml-graphics sfml-window sfml-system
)

#Copia los recursos utilizados
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)

#Copia las dll
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${SFML_DIR}/../../../bin $<TARGET_FILE_DIR:${PROJECT_NAME}>)