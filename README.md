# dwm config

Personal dwm configuration with keybindings ported from Hyprland.

## Patches

- vanitygaps - configurable gaps between windows
- stacker - better window stack navigation and movement
- bstack - bottom stack layout
- togglefullscreen - proper fullscreen toggle

## Building

Requires Nix package manager:

```bash
nix-shell
make
sudo make install
```

Or on a traditional system, install these dependencies:
- libX11, libXinerama, libXft, libxcb
- freetype, fontconfig
- gcc, make, pkg-config

## Keybindings

### Window Management

| Key | Action |
|-----|--------|
| `SUPER+Return` | Terminal (ghostty) |
| `SUPER+Q` | Kill window |
| `SUPER+Shift+Q` | Quit dwm |
| `SUPER+E` | File manager (thunar) |
| `SUPER+P` | Launcher (rofi) |
| `SUPER+V` | Toggle floating |
| `SUPER+D` | Toggle fullscreen |
| `SUPER+Shift+F` | Toggle fullscreen |

### Navigation

| Key | Action |
|-----|--------|
| `SUPER+J` | Focus next window |
| `SUPER+K` | Focus previous window |
| `SUPER+Shift+J` | Move window down in stack |
| `SUPER+Shift+K` | Move window up in stack |
| `SUPER+Shift+Return` | Swap with master |
| `SUPER+Tab` | View previous tag |

### Layout

| Key | Action |
|-----|--------|
| `SUPER+H` | Decrease master size |
| `SUPER+L` | Increase master size |
| `SUPER+I` | Add window to master |
| `SUPER+Shift+D` | Remove window from master |
| `SUPER+T` | Tiled layout |
| `SUPER+F` | Floating layout |
| `SUPER+M` | Monocle layout |
| `SUPER+Shift+B` | Bottom stack layout |
| `SUPER+Space` | Toggle last layout |
| `SUPER+B` | Toggle bar |

### Tags (Workspaces)

| Key | Action |
|-----|--------|
| `SUPER+1-9` | View tag 1-9 |
| `SUPER+Shift+1-9` | Move window to tag 1-9 |
| `SUPER+0` | View all tags |
| `SUPER+Shift+0` | Tag window to all |

### Multi-Monitor

| Key | Action |
|-----|--------|
| `SUPER+,` | Focus previous monitor |
| `SUPER+.` | Focus next monitor |
| `SUPER+Shift+,` | Move window to previous monitor |
| `SUPER+Shift+.` | Move window to next monitor |

### Gaps

| Key | Action |
|-----|--------|
| `SUPER+Alt+H` | Increase gaps |
| `SUPER+Alt+L` | Decrease gaps |
| `SUPER+Alt+0` | Toggle gaps |
| `SUPER+Alt+Shift+0` | Reset gaps to default |

### Media Keys

| Key | Action |
|-----|--------|
| `XF86AudioRaiseVolume` | Volume up (pamixer) |
| `XF86AudioLowerVolume` | Volume down (pamixer) |
| `XF86AudioMute` | Toggle mute |
| `XF86AudioMicMute` | Toggle mic mute |
| `XF86AudioPlay/Pause` | Play/pause (playerctl) |
| `XF86AudioNext` | Next track |
| `XF86AudioPrev` | Previous track |
| `XF86MonBrightnessUp` | Brightness up |
| `XF86MonBrightnessDown` | Brightness down |
| `Print` | Screenshot (flameshot) |

## Appearance

- Border: 1px
- Inner gaps: 5px
- Outer gaps: 20px
- Font: monospace 10, Noto Color Emoji 15

## Window Rules

- Thunar: floating
- Gimp: floating
- Firefox: tag 9

## Dependencies (runtime)

- ghostty - terminal
- rofi - launcher
- thunar - file manager
- pamixer - volume control
- playerctl - media control
- brightnessctl - brightness control
- flameshot - screenshots
