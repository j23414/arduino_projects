# README

## Step 1: Start sensors

Use Arudino IDE to load `soil_moisture_sensor.ino` to Arduino Uno chip.

## Step 2: Start collecting values. 

Open a terminal on the Raspberry Pi and start the listen2serial.py code. This will write the sensor values to `output.txt` along with a timestamp.

```
python3 listen2serial.py
```

## Step 3: Send values to your email

Since the hardware will probably have limited memory. Send `output.txt` to researchers every X number of days.

```
python3 gmail.py
```

Probably best to call this with a cronjob (google search cronjobs or crontab). 


