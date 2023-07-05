build: clean
    DOCKER_BUILDKIT=1 docker buildx build -o type=local,dest=result . 
redox:
    DOCKER_BUILDKIT=1 docker buildx build --build-arg="KEYBOARD=redox" -o type=local,dest=result . 
planck:
    DOCKER_BUILDKIT=1 docker buildx build --build-arg="KEYBOARD=planck/rev6" -o type=local,dest=result . 
fetch_totem_src:
    git submodule add -f git@github.com:GEIGEIGEIST/qmk-config-totem.git
    git submodule sync
    ( cd qmk-config-totem && git checkout main )

fetch_qmk:
    echo "Add git sub-modules..."
    git submodule add -f https://github.com/qmk/qmk_firmware
    echo "Update git sub-modules..."
    git submodule sync --recursive
    git submodule update --init --recursive --progress
    ( cd qmk_firmware && git checkout "master" )

flash: 
    cp result/result/totem_fride.uf2 /Volumes/RPI-RP2/

redox-flash: redox
    avrdude -p atmega32u4 -c avr109 -U flash:w:/Users/jgf/code/private/totem-qmk/result/result/redox_rev1_base_fride.hex:i -P /dev/cu.cu.usbmodem5301 -C '/Applications/QMK Toolbox.app/Contents/Resources/avrdude.conf'


clean:
    rm -rf result/result/*