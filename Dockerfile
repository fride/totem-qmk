FROM docker.io/qmkfm/base_container:latest as base
RUN pip install qmk && \
    qmk setup -y -H /qmk_firmware
WORKDIR /qmk_firmware
RUN mkdir -p /qmk_firmware/keyboards/totem
RUN mkdir -p /qmk_firmware/users/fride
RUN mkdir -p /qmk_firmware/keyboards/totem/keymaps/totem
RUN mkdir -p /qmk_firmware/keyboards/redox/keymaps/fride

COPY ./qmk-config-totem/totem/ /qmk_firmware/keyboards/totem/
COPY ./src/keymaps/totem/ /qmk_firmware/keyboards/totem/keymaps/fride/
COPY ./src/keymaps/planck/ /qmk_firmware/keyboards/planck/keymaps/fride/
COPY ./src/keymaps/redox/ /qmk_firmware/keyboards/redox/keymaps/fride/
COPY ./src/keymaps/ferris/ /qmk_firmware/keyboards/ferris/keymaps/fride/
COPY ./src/users/fride/ /qmk_firmware/users/fride/
# make bash as default command
CMD ["/bin/bash"]

ARG KEYMAP=fride
ARG KEYBOARD=totem
FROM base as build
RUN qmk compile -kb ${KEYBOARD} -km fride
# RUN qmk compile -kb ferris/0_2 -km fride

FROM scratch as result
COPY  --from=build /qmk_firmware/.build ./result/