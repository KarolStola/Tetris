export PROJ_NAME = Tetris
export EXE = $(PROJ_NAME)
APP_NAME = $(PROJ_NAME).app

SRC_DIR = src

all : app
	$(MAKE) -C $(SRC_DIR) $@

$(EXE) :
	$(MAKE) -C $(SRC_DIR) $@

clean:
	$(MAKE) -C $(SRC_DIR) $@;
	rm -rf $(APP_NAME)
	
run:
	open $(APP_NAME)

app: $(EXE)
	rm -rf $(APP_NAME);
	mkdir -p $(APP_NAME);
	cd $(APP_NAME);
	mkdir -p $(APP_NAME)/Contents;
	mkdir -p $(APP_NAME)/Contents/MacOS;
	mkdir -p $(APP_NAME)/Contents/Resources;
	cp Info.plist $(APP_NAME)/Contents/;
	cp $(EXE) $(APP_NAME)/Contents/MacOS/$(PROJ_NAME);
	cp -R assets $(APP_NAME)/Contents/Resources/;
	cp -Rf Frameworks/* $(APP_NAME)/Contents/Resources;