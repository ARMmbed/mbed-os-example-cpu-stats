![](./resources/official_armmbed_example_badge.png)
# CPU statistics Mbed OS example

This guide reviews the steps required to get CPU statistics and usage on an Mbed OS enabled platform.

You can build this project with all supported [Mbed OS build tools](https://os.mbed.com/docs/mbed-os/latest/tools/index.html). However, this example project specifically refers to the command-line interface tool [Arm Mbed CLI](https://github.com/ARMmbed/mbed-cli#installing-mbed-cli).

1. Install Mbed CLI.
1. Clone this repository on your system.
1. Change the current directory to where the project was cloned.

## Application functionality

The `main()` function starts a thread that blinks an LED at varying intervals to keep the CPU busy. It also creates an event queue and adds a function to periodically print these statistics:

   - The time spent while up, in idle mode, in sleep mode and in deep sleep mode since the system started.
   - The percentage of CPU usage and idleness since the last call.

## Building and running

1. Connect a USB cable between the USB port on the target and the host computer.
1. Run this command to build the example project and program the microcontroller flash memory:

    ```bash
    $ mbed compile -m <TARGET> -t <TOOLCHAIN> --flash --sterm
    ```

Note: You can use the Mbed CLI command-line option "--sterm" to open a serial terminal after flashing.

Your PC may take a few minutes to compile your code.

The binary is located at `./BUILD/<TARGET>/<TOOLCHAIN>/mbed-os-example-cpu-stats.bin`.

Alternatively, you can manually copy the binary to the target, which gets mounted on the host computer through USB.

Depending on the target, you can build the example project with the `GCC_ARM`, `ARM` or `IAR` toolchain. After installing Arm Mbed CLI, run the command below to determine which toolchain supports your target:

```bash
$ mbed compile -S
```

## Expected output

The LED blinks, and the serial terminal shows an output similar to:

```
--- Terminal on /dev/ttyACM0 - 9600,8,N,1 ---
Time(us): Up: 2000061   Idle: 1999817   Sleep: 0   DeepSleep: 1999817
Idle: 99% Usage: 1%

Time(us): Up: 4000061   Idle: 3901337   Sleep: 0   DeepSleep: 3901337
Idle: 95% Usage: 5%

Time(us): Up: 6000061   Idle: 5803649   Sleep: 0   DeepSleep: 5803649
Idle: 95% Usage: 5%

Time(us): Up: 8000061   Idle: 7706603   Sleep: 0   DeepSleep: 7706603
Idle: 95% Usage: 5%

Time(us): Up: 10000061   Idle: 9608855   Sleep: 0   DeepSleep: 9608855
Idle: 95% Usage: 5%

Time(us): Up: 12000061   Idle: 11510464   Sleep: 0   DeepSleep: 11510464
Idle: 95% Usage: 5%

Time(us): Up: 14000061   Idle: 13410215   Sleep: 0   DeepSleep: 13410215
Idle: 94% Usage: 6%

Time(us): Up: 16000030   Idle: 14309537   Sleep: 0   DeepSleep: 14309537
Idle: 44% Usage: 56%
```

The information below shows how to interpret the above fields:

```
Uptime:          Time(us) since the system has started
Idle time:       Time(us) spent in the idle thread since the system has started
Sleep time:      Time(us) spent in sleep since the system has started
DeepSleep time:  Time(us) spent in deep sleep since the system has started
Idle:            Percentage of time spent in idle thread
Usage:           Percentage fo time spent in computing
```

## Configuring the application

You can enable CPU statistics by setting `platform.cpu-stats-enabled` to true in the application configuration file:

```
{
    "target_overrides": {
        "*": {            
            "platform.cpu-stats-enabled": true            
        }
    }
}
```

## Troubleshooting

If you have problems, you can review the [documentation](https://os.mbed.com/docs/latest/tutorials/debugging.html) for suggestions on what could be wrong and how to fix it.

## Related links

* [Mbed OS Stats API](https://os.mbed.com/docs/latest/apis/mbed-statistics.html).
* [Mbed OS configuration](https://os.mbed.com/docs/latest/reference/configuration.html).
* [Mbed OS serial communication](https://os.mbed.com/docs/latest/tutorials/serial-communication.html).
* [Mbed boards](https://os.mbed.com/platforms/).

### License and contributions

The software is provided under the Apache-2.0 license. Contributions to this project are accepted under the same license. Please see contributing.md for more info.

This project contains code from other projects. The original license text is included in those source files. They must comply with our license guide.
