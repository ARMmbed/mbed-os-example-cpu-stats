# Testing examples

Examples are tested using tool [htrun](https://github.com/ARMmbed/mbed-os-tools/tree/master/packages/mbed-host-tests) and templated print log. 

To run the test, use following command after you build the example:
```
mbedhtrun -d <MOUNT_POINT> -p <SERIAL_PORT> -m <TARGET> -f .\BUILD\<TARGET>\<TOOLCHAIN>\mbed-os-example-cpu-stats.bin --compare-log tests\cpu-stats.log
```

For example:
```
mbedhtrun -d D: -p COM4 -m K64F -f .\BUILD\K64F\GCC_ARM\mbed-os-example-cpu-stats.bin --compare-log tests\cpu-stats.log
```

More details on:
- [mbedls](https://github.com/ARMmbed/mbed-os-tools/blob/master/packages/mbed-ls/README.md#mbed-ls) to find your target `MOUNT_POINT` and `SERIAL_PORT`.
