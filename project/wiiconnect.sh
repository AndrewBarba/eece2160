#!/bin/bash

bluez-simple-agent hci0 8C:56:C5:3F:37:DE
bluez-test-device trusted 8C:56:C5:3F:37:DE yes
bluez-test-input connect 8C:56:C5:3F:37:DE
