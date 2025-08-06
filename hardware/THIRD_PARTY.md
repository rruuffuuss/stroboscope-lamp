# Third-party material

`hardware/third_party/kicad-lib-arduino/` contains g200kg's Arduino KiCad library from https://github.com/g200kg/kicad-lib-arduino at commit `bbae574b9f01445f94c4b670fe42c8b0b0312928`.

The library's upstream README, images and CC0 license are included. Its 3D model paths use `${KIPRJMOD}/../third_party/kicad-lib-arduino/` so they resolve from `hardware/controller/`.

The project-local symbol and footprint tables in `hardware/controller/` reference this library. Standard KiCad libraries must be installed separately.
