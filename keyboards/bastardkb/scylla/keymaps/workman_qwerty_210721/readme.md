**Modified version of Workman with a QWERTY layer**
* https://docs.qmk.fm/newbs_getting_started
* https://github.com/qmk/qmk_firmware.git
* https://github.com/qmk/qmk_toolbox

1. Clone repo
2. brew install qmk/qmk/qmk
3. qmk setup
4. qmk compile -kb bastardkb/scylla/v1/elitec -km default
5. .hex saved in qmk_firmware root folder
6. qmk compile -kb bastardkb/scylla/v1/elitec -km workman_qwerty_210721
7. Flash both sides separately using QMK Toolbox

** New board with stilettos now uses splinktegrated; BastardKB repo found at
https://github.com/Bastardkb/bastardkb-qmk/tree/bkb-master/keyboards/bastardkb/scylla
