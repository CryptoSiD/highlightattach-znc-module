# ZNC Highlight Reattach Module

A simple ZNC module that automatically reattaches you to detached channels when someone mentions your nickname.

## What it does

When you're detached from a channel and someone mentions your nick in a message, notice, or action, this module will automatically rejoin you to that channel so you don't miss the conversation.

## Features

- Lightweight and simple - no configuration needed
- Works with channel messages, notices, and actions
- Only reattaches when you're actually detached
- Case-insensitive nickname matching

## Installation

1. Clone the repository or download the `highlightattach.cpp` file:
   ```bash
   git clone https://github.com/CryptoSiD/highlightattach-znc-module.git
   cd znc-highlightattach
   ```
2. Compile the module:
   ```bash
   znc-buildmod highlightattach.cpp
   ```
3. Load the module in ZNC:
   ```irc
   /msg *status loadmod highlightattach
   ```

## Usage

Once loaded, the module works automatically in the background. No commands or configuration required.

- When detached from a channel, any mention of your nickname will cause you to rejoin
- The module is completely transparent - it just works
- To disable, simply unload the module: 
  ```irc
  /msg *status unloadmod highlightattach
  ```

## Requirements

- ZNC 1.0 or later
- Compiled with the ZNC development headers

## License

GNU General Public License version 2

## Contributing

Feel free to submit issues or pull requests to improve the module.
