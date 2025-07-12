# Unlimited Stamina - GTA San Andreas Plugin

A plugin that provides unlimited stamina for CJ in GTA San Andreas, allowing you to run, sprint, swim, and cycle indefinitely without getting tired.

## Features

- **Unlimited Stamina**: Never run out of stamina while running, swimming, or cycling
- **Toggle On/Off**: Enable or disable the mod with a keypress
- **Configuration**: Customizable settings via INI file
- **Non-Intrusive**: No permanent changes to game files
- **Compatible**: Works with most other mods

## Installation

1. Make sure you have [GTA San Andreas](https://store.steampowered.com/app/12120/Grand_Theft_Auto_San_Andreas/) installed
2. Install [Plugin SDK](https://github.com/DK22Pac/plugin-sdk) if you haven't already
3. Copy the `unlimited-stamina-SA.asi` file to your GTA San Andreas installation folder
4. Launch the game and enjoy unlimited stamina!

## Controls

- **F7**: Toggle unlimited stamina on/off
- **F8**: Toggle notification messages on/off

## Configuration

The plugin creates a configuration file `unlimited-stamina.ini` in your GTA San Andreas folder with the following options:

```ini
[Settings]
# Unlimited Stamina Plugin Configuration
EnableUnlimitedStamina=true
ShowNotifications=true
```

You can edit this file with any text editor to change the default settings.

## Building from Source

### Requirements

- Visual Studio 2022
- [Plugin SDK](https://github.com/DK22Pac/plugin-sdk)

### Steps

1. Clone this repository
2. Set the environment variable `PLUGIN_SDK_DIR` to your Plugin SDK installation folder
3. Set the environment variable `GTA_SA_DIR` to your GTA San Andreas installation folder
4. Open the solution in Visual Studio
5. Build the solution

## Technical Details

This plugin works by:
- Setting the player's stamina stat to maximum value
- Setting the player's stamina value in the player data structure
- Using script commands to prevent the player from getting tired

## Compatibility

- Compatible with GTA San Andreas v1.0 US
- May work with other versions, but not tested

## Troubleshooting

**Problem**: The plugin doesn't load
- Make sure you have the correct version of GTA San Andreas (v1.0 US)
- Check if you have ASI Loader installed
- Make sure the .asi file is in the correct directory

**Problem**: The mod doesn't work even when enabled
- Make sure there are no conflicting mods
- Try reinstalling the plugin

## License

This project is open source and available under the MIT License.

## Credits

- Developed using [Plugin SDK](https://github.com/DK22Pac/plugin-sdk)
- Thanks to the GTA modding community for their support and resources 