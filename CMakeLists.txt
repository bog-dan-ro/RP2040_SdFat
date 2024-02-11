cmake_minimum_required(VERSION 3.13)

add_library(SdFat INTERFACE)

target_compile_definitions(SdFat INTERFACE
    RP2040
    SPI_DRIVER_SELECT=3
)

set(SRC_PATH ${CMAKE_CURRENT_LIST_DIR}/src)

target_sources(SdFat INTERFACE
    ${SRC_PATH}/common/ArduinoFiles.h
    ${SRC_PATH}/common/CompileDateTime.h
    ${SRC_PATH}/common/CPPLINT.cfg
    ${SRC_PATH}/common/DebugMacros.h
    ${SRC_PATH}/common/FmtNumber.cpp
    ${SRC_PATH}/common/FmtNumber.h
    ${SRC_PATH}/common/FsApiConstants.h
    ${SRC_PATH}/common/FsBlockDevice.h
    ${SRC_PATH}/common/FsBlockDeviceInterface.h
    ${SRC_PATH}/common/FsCache.cpp
    ${SRC_PATH}/common/FsCache.h
    ${SRC_PATH}/common/FsDateTime.cpp
    ${SRC_PATH}/common/FsDateTime.h
    ${SRC_PATH}/common/FsName.cpp
    ${SRC_PATH}/common/FsName.h
    ${SRC_PATH}/common/FsStructs.cpp
    ${SRC_PATH}/common/FsStructs.h
    ${SRC_PATH}/common/FsUtf.cpp
    ${SRC_PATH}/common/FsUtf.h
    ${SRC_PATH}/common/SysCall.h
    ${SRC_PATH}/common/upcase.cpp
    ${SRC_PATH}/common/upcase.h

    #${SRC_PATH}/DigitalIO/boards/
    ${SRC_PATH}/DigitalIO/DigitalPin.h
    ${SRC_PATH}/DigitalIO/SoftSPI.h

    ${SRC_PATH}/ExFatLib/ExFatDbg.cpp
    ${SRC_PATH}/ExFatLib/ExFatFile.cpp
    ${SRC_PATH}/ExFatLib/ExFatFile.h
    ${SRC_PATH}/ExFatLib/ExFatFilePrint.cpp
    ${SRC_PATH}/ExFatLib/ExFatFileWrite.cpp
    ${SRC_PATH}/ExFatLib/ExFatFormatter.cpp
    ${SRC_PATH}/ExFatLib/ExFatFormatter.h
    ${SRC_PATH}/ExFatLib/ExFatLib.h
    ${SRC_PATH}/ExFatLib/ExFatName.cpp
    ${SRC_PATH}/ExFatLib/ExFatPartition.cpp
    ${SRC_PATH}/ExFatLib/ExFatPartition.h
    ${SRC_PATH}/ExFatLib/ExFatVolume.cpp
    ${SRC_PATH}/ExFatLib/ExFatVolume.h

    ${SRC_PATH}/FatLib/FatDbg.cpp
    ${SRC_PATH}/FatLib/FatFile.cpp
    ${SRC_PATH}/FatLib/FatFile.h
    ${SRC_PATH}/FatLib/FatFileLFN.cpp
    ${SRC_PATH}/FatLib/FatFilePrint.cpp
    ${SRC_PATH}/FatLib/FatFileSFN.cpp
    ${SRC_PATH}/FatLib/FatFormatter.cpp
    ${SRC_PATH}/FatLib/FatFormatter.h
    ${SRC_PATH}/FatLib/FatLib.h
    ${SRC_PATH}/FatLib/FatName.cpp
    ${SRC_PATH}/FatLib/FatPartition.cpp
    ${SRC_PATH}/FatLib/FatPartition.h
    ${SRC_PATH}/FatLib/FatVolume.cpp
    ${SRC_PATH}/FatLib/FatVolume.h

    ${SRC_PATH}/FsLib/FsFile.cpp
    ${SRC_PATH}/FsLib/FsFile.h
    ${SRC_PATH}/FsLib/FsFormatter.h
    ${SRC_PATH}/FsLib/FsLib.h
    ${SRC_PATH}/FsLib/FsNew.cpp
    ${SRC_PATH}/FsLib/FsNew.h
    ${SRC_PATH}/FsLib/FsVolume.cpp
    ${SRC_PATH}/FsLib/FsVolume.h


    ${SRC_PATH}/SdCard/SdCard.h
    ${SRC_PATH}/SdCard/SdCardInfo.cpp
    ${SRC_PATH}/SdCard/SdCardInfo.h
    ${SRC_PATH}/SdCard/SdCardInterface.h
    ${SRC_PATH}/SdCard/SdioCard.h
    ${SRC_PATH}/SdCard/SdioTeensy.cpp
    ${SRC_PATH}/SdCard/SdioTeensy.h
    ${SRC_PATH}/SdCard/SdSpiCard.cpp
    ${SRC_PATH}/SdCard/SdSpiCard.h

    ${SRC_PATH}/SpiDriver/SdSpiBaseClass.h
    ${SRC_PATH}/SpiDriver/SdSpiDriver.h

    ${SRC_PATH}/BufferedPrint.h
    ${SRC_PATH}/FreeStack.cpp
    ${SRC_PATH}/FreeStack.h
    ${SRC_PATH}/MinimumSerial.cpp
    ${SRC_PATH}/MinimumSerial.h
    ${SRC_PATH}/RingBuf.h
    ${SRC_PATH}/SdFat.h
    ${SRC_PATH}/sdios.h

    ${CMAKE_CURRENT_LIST_DIR}/extras/attic/PrintBasic.cpp
)

target_include_directories(SdFat INTERFACE
    ${SRC_PATH}
    ${CMAKE_CURRENT_LIST_DIR}/extras/attic
)

target_link_libraries(SdFat INTERFACE
    hardware_spi
    pico_stdlib
)
