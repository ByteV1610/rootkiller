# Android RootKiller

RootKiller is a executable tool designed to enhance the security of game hack plugins, particularly for game reversers who may encounter issues such as Traffic Capturing, bypass dumping, or reverse engineering attempts. It works by terminating other root-granted apps running on the device.

## Features

- Kills root-granted apps running on the device.
- Utilizes the `magisk.db` database to identify and terminate root apps.
- Support All Android
- Exception In Killing For Own Application by UID

## How It Works

RootKiller operates by continuously scanning the device for root-granted apps using information stored in the `magisk.db` database. It identifies these apps and terminates them. By requiring root access, RootKiller offers game reversers an additional layer of protection for their apps and helps safeguard against unauthorized dumping or malicious activities.

## Build and Installation
Build:
  ```shell
  git clone https://github.com/ByteV1610/rootkiller.git
  cd rootkiller
  ndk-build (Add ndk-build to your env variables)
  adb push rootkiller /data/local/tmp
  ```
  Usage:
   ```shell
  su
  cd /data/local/tmp
  chmod 777 rootkiller
  ./rootkiller <UID_OF_APK_WHICH_IS_NOT_TO_BE_KILLED>
  ```
