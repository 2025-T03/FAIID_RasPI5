// primary reference https://docs.espressif.com/projects/esp-idf/en/v5.0/esp32s3/api-reference/peripherals/i2s.html

// #include <ESP_I2S.h>
#include <wav_header.h>

#include "driver/i2s.h"
#include "driver/i2s_tdm.h"
#include "driver/i2s_common.h"
#include <stdio.h>
#include "driver/gpio.h"

i2s_chan_handle_t rx_handle;

void setup() {
  // put your setup code here, to run once:
  // SETS CHANNEL TO TDM MODE
  i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(I2S_NUM_AUTO, I2S_ROLE_MASTER);//, &I2S_PIN);
  i2s_new_channel(&chan_cfg, NULL, &rx_handle);

  // INIT CHANNEL TO TDM 
  i2s_tdm_config_t tdm_cfg = {
    .clk_cfg = I2S_TDM_CLK_DEFAULT_CONFIG(44100),
    .slot_cfg = I2S_TDM_PCM_LONG_SLOT_DEFAULT_CONFIG(I2S_DATA_BIT_WIDTH_16BIT, I2S_SLOT_MODE_STEREO, i2s_tdm_slot_mask_t (I2S_TDM_SLOT0 | I2S_TDM_SLOT1 | I2S_TDM_SLOT2 | I2S_TDM_SLOT3)),
    .gpio_cfg = {
        .mclk = I2S_GPIO_UNUSED,
        .bclk = GPIO_NUM_4, // pin: D3
        .ws = GPIO_NUM_5, // pin: D4
        .dout = I2S_GPIO_UNUSED,
        .din = GPIO_NUM_18, // pin: D8
        .invert_flags = {
            .mclk_inv = false,
            .bclk_inv = false,
            .ws_inv = false,
        },
    },
  };
  i2s_channel_init_tdm_mode(rx_handle, &tdm_cfg);
}

void loop() {
  // put your main code here, to run repeatedly:

}
