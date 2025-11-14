/*****************************************************
 *  config.h – Freematics TELELOGGER build flags     *
 *  (full version, 9 Aug 2025)                        *
 *****************************************************/

#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

/* ───────────────────────────────
   0. Console / debug
   ─────────────────────────────── */
#define ENABLE_SERIAL_OUT              1          /* show log on USB (115200) */

/* ───────────────────────────────
   1. Data storage
   ─────────────────────────────── */
#define STORAGE_NONE                   0
#define STORAGE_SPIFFS                 1
#define STORAGE_SD                     2
#define STORAGE                        STORAGE_SD  /* SD keeps “logger” alive */

/* ───────────────────────────────
   2. Sensors & vehicle I/O
   ─────────────────────────────── */
#define ENABLE_OBD                     1
#define ENABLE_MEMS                    1
#define GNSS                           1          /* 0:none - 1:stand-alone GPS */
#define MAX_OBD_ERRORS                 3

/* ───────────────────────────────
   3. Wi-Fi (station mode)
   ─────────────────────────────── */
#define ENABLE_WIFI                    1
#define WIFI_SSID                      "Abdullah"
#define WIFI_PASSWORD                  "abdu1213"
#define WIFI_JOIN_TIMEOUT              30000      /* ms */

/* ───────────────────────────────
   4. Server & protocol
   ─────────────────────────────── */
#define PROTOCOL_UDP                   1
#define PROTOCOL_HTTPS_GET             2
#define PROTOCOL_HTTPS_POST            3

#define SERVER_HOST                    "95.179.243.111"
#define SERVER_PROTOCOL                PROTOCOL_UDP     /* UDP selected         */
#define SERVER_PORT                    5000
#define SERVER_PATH                    "/hub/api"       /* needed even for UDP  */

/* ───────────────────────────────
   5.  Cellular modem placeholders
   ─────────────────────────────── */
#define CELL_APN                       ""          /* fill when you use LTE   */
#define APN_USERNAME                   ""          /* empty = no auth         */
#define APN_PASSWORD                   ""          /* empty = no auth         */
#define SIM_CARD_PIN                   ""

/* ───────────────────────────────
   6. Buffer sizes (PSRAM vs. no-PSRAM)
   ─────────────────────────────── */
#define BOARD_HAS_PSRAM                1          /* ESP32-WROVER modules    */
#if BOARD_HAS_PSRAM
  #define BUFFER_SLOTS                 1024
  #define BUFFER_LENGTH                384
  #define SERIALIZE_BUFFER_SIZE        4096
#else
  #define BUFFER_SLOTS                 32
  #define BUFFER_LENGTH                256
  #define SERIALIZE_BUFFER_SIZE        1024
#endif

/* ───────────────────────────────
   7. Timing / watchdogs
   ─────────────────────────────── */
#define SERVER_SYNC_INTERVAL           120        /* s (0 = disabled)        */
#define DATA_INTERVAL_TABLE            {1000,2000,5000} /* ms while moving     */
#define STATIONARY_TIME_TABLE          {10,60,180}      /* s while parked      */
#define PING_BACK_INTERVAL             900        /* s between keep-alive    */
#define SIGNAL_CHECK_INTERVAL          10         /* s between RSSI checks   */
#define MAX_CONN_ERRORS_RECONNECT      5          /* errors → reset modem    */
#define MAX_CONN_TIME                  10000      /* ms allowed to connect   */
#define DATA_RECEIVING_TIMEOUT         5000       /* ms waiting for reply    */

/* ───────────────────────────────
   8. GNSS options
   ─────────────────────────────── */
#define GNSS_ALWAYS_ON                 0
#define GNSS_RESET_TIMEOUT             300        /* s without fix → reset   */

/* ───────────────────────────────
   9. Wake-up conditions
   ─────────────────────────────── */
#define MOTION_THRESHOLD               0.4f       /* G-force                 */
#define JUMPSTART_VOLTAGE              14         /* V                       */
#define RESET_AFTER_WAKEUP             1

/* ───────────────────────────────
  10. Misc hardware pins / features
   ─────────────────────────────── */
#define PIN_SENSOR1                    34
#define PIN_SENSOR2                    26
#define COOLING_DOWN_TEMP              75         /* °C                      */

#define ENABLE_HTTPD                   0          /* onboard Web UI          */
#define ENABLE_BLE                     1          /* BLE SPP for Controller  */

#endif /* CONFIG_H_INCLUDED */
