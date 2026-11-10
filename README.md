# capi-hello-world

A minimal [CAPI](https://github.com/analogdevicesinc/capi) app.
It prints `Hello, World! (#<n>)` on the console UART once a second.

## CAPI setup

You need CMake 3.27+, Ninja, Python 3 and network access. Clone capi and this
app into one workspace:

```bash
mkdir ~/workspace && cd ~/workspace
git clone https://github.com/analogdevicesinc/capi
git clone https://github.com/analogdevicesinc/capi-hello-world
```

```bash
export CAPI_WORKSPACE=~/workspace
export CAPI_DIR=~/workspace/capi
```

The first configure clones the platform (capi-maxim, capi-stm32 or capi-alif)
into the workspace.

## Platform setup

**Alif.** Install `arm-none-eabi-gcc` with newlib. To flash, set
`ALIF_SETOOLS_PATH`.

```bash
export ALIF_CMSIS_DFP_PATH=/path/to/alif_ensemble-cmsis-dfp
export CMSIS_6_PATH=/path/to/CMSIS_6
```

**Maxim.** Install `arm-none-eabi-gcc` with newlib (on macOS
`brew install --cask gcc-arm-embedded`). To flash, use ADI's OpenOCD, not
mainline (`-DOPENOCD_PATH=`). Get MSDK:

```bash
git clone https://github.com/analogdevicesinc/msdk.git ~/workspace/msdk
export MAXIM_SDK_PATH=~/workspace/msdk
```

**STM32.** Install STM32CubeIDE and STM32CubeMX. NUCLEO-C5A3ZG also needs
STM32CubeMX2. Without CubeIDE, add `-DUSE_VENDOR_TOOLCHAIN=OFF` at configure to
use the GCC in `PATH`.

## Build and flash

Run in `~/workspace/capi-hello-world`:

```bash
cmake --preset <preset>
cmake --build <build dir> --target flash
```

| Platform | Preset | Build dir |
|---|---|---|
| Alif | `dk-e8-rtss-hp`, `dk-e8-rtss-he` | `build-alif/rtss_hp`, `build-alif/rtss_he` |
| Maxim | `max32655fthr`, `max32650fthr` | `build-maxim/<preset>` |
| STM32 | `nucleo-h753zi`, `nucleo-c5a3zg` | `build-stm32/<preset>` |

## License

BSD-3-Clause.
