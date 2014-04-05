CC = g++
LD = $(CC)
CFLAGS = -c -std=c++11
LFLAGS = -rpath @loader_path/../Resources -F../Frameworks/ -framework Cocoa -framework SDL2 -framework SDL2_ttf -framework SDL2_image
#-L../lib -rpath ./lib/ -rpath ../Resources/lib/
#-lSDL2 -lSDL2-2.0.0 -lSDL2_image -lSDL2_ttf

EXE_LOCATION = ../
SRC_SUFFIX = .cpp
OBJ_SUFFIX = .o
HEADER_SUFFIX = .h

OBJ_DIR = build

# modules
#######################
MAIN_MODULES = main

LOGIC_DIR = logic
LOGIC_MODULES = Tetris
LOGIC_MODULES := $(addprefix $(LOGIC_DIR)/, $(LOGIC_MODULES))

SCENE_DIR = $(LOGIC_DIR)/scenes
SCENE_MODULES = TetrisSceneManager TetrisScene
SCENE_MODULES := $(addprefix $(SCENE_DIR)/, $(SCENE_MODULES))

MAIN_MENU_DIR = $(SCENE_DIR)/TetrisMainMenu
MAIN_MENU_MODULES = TetrisMainMenu
MAIN_MENU_MODULES := $(addprefix $(MAIN_MENU_DIR)/, $(MAIN_MENU_MODULES))

GAME_SCENE_DIR = $(SCENE_DIR)/TetrisGameScene
GAME_SCENE_MODULES = TetrisGameScene
GAME_SCENE_MODULES := $(addprefix $(GAME_SCENE_DIR)/, $(GAME_SCENE_MODULES))

GAME_FIELD_DIR = $(GAME_SCENE_DIR)/game_field
GAME_FIELD_MODULES = TetrisGameField TetrisGameFieldMesh TetrisOccupationMatrix
GAME_FIELD_MODULES := $(addprefix $(GAME_FIELD_DIR)/, $(GAME_FIELD_MODULES))

TETROMINO_DIR = $(GAME_SCENE_DIR)/tetrominos
TETROMINO_MODULES = Tetromino TetrisBrick Tetrominos TetrominoChooser
TETROMINO_MODULES := $(addprefix $(TETROMINO_DIR)/, $(TETROMINO_MODULES))

EVENT_DIR = $(LOGIC_DIR)/events
EVENT_MODULES = TetrisEventHandler TetrisEvent
EVENT_MODULES := $(addprefix $(EVENT_DIR)/, $(EVENT_MODULES))

TIME_DIR = $(LOGIC_DIR)/time
TIME_MODULES = TetrisTimer TetrisTimeManager
TIME_MODULES := $(addprefix $(TIME_DIR)/, $(TIME_MODULES))

DISPLAY_DIR = display
DISPLAY_MODULES = TetrisGraphicsInitializer TetrisWindow TetrisSpritesheet TetrisSprite TetrisDrawable TetrisDrawer TetrisAssetConsumer TetrisTextLabel
DISPLAY_MODULES := $(addprefix $(DISPLAY_DIR)/, $(DISPLAY_MODULES))

EXCEPTION_DIR = exceptions
EXCEPTION_MODULES = TetrisException
EXCEPTION_MODULES := $(addprefix $(EXCEPTION_DIR)/, $(EXCEPTION_MODULES))

MODULES = $(MAIN_MODULES)
MODULES += $(LOGIC_MODULES) $(TIME_MODULES) $(EVENT_MODULES)
MODULES += $(SCENE_MODULES) $(GAME_SCENE_MODULES) $(GAME_FIELD_MODULES) $(MAIN_MENU_MODULES)
MODULES += $(TETROMINO_MODULES) #$(BRICK_MODULES)
MODULES += $(DISPLAY_MODULES)
MODULES += $(EXCEPTION_MODULES)

# modules directories
#######################
MODULES_DIRS = $(LOGIC_DIR) $(SCENE_DIR) $(MAIN_MENU_DIR)
MODULES_DIRS += $(GAME_SCENE_DIR) $(GAME_FIELD_DIR) $(TETROMINO_DIR)
MODULES_DIRS += $(EVENT_DIR) $(TIME_DIR)
MODULES_DIRS += $(DISPLAY_DIR)  $(EXCEPTION_DIR)

# objects directories
#######################
OBJS_DIRS = $(addprefix $(OBJ_DIR)/, $(MODULES_DIRS))

# sources
#######################
SOURCES = $(addsuffix $(SRC_SUFFIX), $(MODULES))

# headers
#######################
HEADERS = $(SOURCES:$(SRC_SUFFIX)=$(HEADER_SUFFIX))

# objects
#######################
OBJECTS = $(SOURCES:$(SRC_SUFFIX)=$(OBJ_SUFFIX))

# rules
#######################
all: $(EXE)

$(EXE): $(OBJECTS)
	$(LD) $^ -o $(EXE_LOCATION)$@ $(LFLAGS)

%$(OBJ_SUFFIX): %$(SRC_SUFFIX)
	$(CC) $^ -o $@ $(CFLAGS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	$(foreach dir, $(OBJS_DIRS), mkdir -p $(dir);)

clean:
	rm -f $(EXE_LOCATION)$(EXE) $(OBJECTS);
	rm -rf $(OBJ_DIR);