### ESP32-PT100

Reads PT100 temperature using MAX31865 board.

#### Issue with clone MAX31865 board

If your MAX31865 board is connected correctly but shows values over 700 C, unless 3.3V is disconnect and reconnected.

#### Solution

desolder the capacitor above the SDO pin and bridge the gap using solder.

The temperature should be correct now.