#include "SdFat.h"
#include "stdio.h"
#include <hardware/gpio.h>
#include <hardware/spi.h>
#include <tusb.h>

// SD chip select pin.
#define SD_CS_PIN SD_SS

// This is a simple driver based on the the standard SPI.h library.
// You can write a driver entirely independent of SPI.h.
// It can be optimized for your board or a different SPI port can be used.
// The driver must be derived from SdSpiBaseClass.
// See: SdFat/src/SpiDriver/SdSpiBaseClass.h
class MySpiClass : public SdSpiBaseClass {
 public:
     // Activate SPI hardware with correct speed and mode.
     void activate() {}
     // Initialize the SPI bus.
     void begin(SdSpiConfig config)
     {
         spi_init(instance, 1000 * 1000);
         spi_set_format(instance, 8, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
         gpio_set_function(SD_MOSI, GPIO_FUNC_SPI);
         gpio_set_function(SD_MISO, GPIO_FUNC_SPI);
         gpio_set_function(SD_SCK, GPIO_FUNC_SPI);
         gpio_set_slew_rate(SD_SCK, GPIO_SLEW_RATE_FAST);
     }

     // Deactivate SPI hardware.
     void deactivate() {}
     // Receive a byte.
     uint8_t receive()
     {
         uint8_t data;
         spi_read_blocking(instance, 0xFF, &data, 1);
         return data;
     }

     // Receive multiple bytes.
     // Replace this function if your board has multiple byte receive.
     uint8_t receive(uint8_t *buf, size_t count)
     {
         spi_read_blocking(instance, 0xFF, buf, count);
         return 0;
     }
     // Send a byte.
     void send(uint8_t data) { spi_write_blocking(instance, &data, 1); }
     // Send multiple bytes.
     // Replace this function if your board has multiple byte send.
     void send(const uint8_t *buf, size_t count) { spi_write_blocking(instance, buf, count); }
     // Save SPISettings for new max SCK frequency
     void setSckSpeed(uint32_t maxSck) { spi_set_baudrate(instance, maxSck); }

 private:
     spi_inst_t *instance = spi0;
} mySpi;

void sdCsWrite(SdCsPin_t pin, bool level)
{
    gpio_put(pin, level);
}

void sdCsInit(SdCsPin_t pin)
{
    gpio_init(pin);
    gpio_put(pin, true);
    gpio_set_dir(pin, GPIO_OUT);
    gpio_put(pin, true);
}

#define SD_CONFIG SdSpiConfig(SD_SS, DEDICATED_SPI, SD_SCK_MHZ(50), &mySpi)

SdFat sd;
struct Serial : public print_t
{
    // PrintBasic interface
public:
    size_t write(uint8_t b) final
    {
        printf("%c", b);
        return 1;
    }
};


//------------------------------------------------------------------------------
int main()
{
    stdio_init_all();
    while (!tud_cdc_connected()) {
        sleep_ms(100);
    }
    Serial ser;
    printf("Hello there \n");
    if (!sd.begin(SD_CONFIG)) {
        sd.initErrorHalt(&ser);
    }
    sd.ls(&ser, LS_SIZE);
    printf("Done\n");
    while (1)
        ;
}
