{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "dwm-dev";

  buildInputs = with pkgs; [
    # Build tools
    gnumake
    gcc
    pkg-config

    # X11 libraries
    xorg.libX11
    xorg.libXinerama
    xorg.libXft
    xorg.libxcb
    xorg.xcbutil

    # Font rendering
    freetype
    fontconfig

    # For media keys header (XF86keysym.h)
    xorg.xorgproto
  ];

  shellHook = ''
    echo "dwm development shell"
    echo "Commands:"
    echo "  make        - compile dwm"
    echo "  make clean  - clean build files"
    echo "  sudo make install - install dwm to /usr/local"
    echo ""
    echo "Keybindings configured from Hyprland:"
    echo "  SUPER+Return  = ghostty"
    echo "  SUPER+Q       = kill window"
    echo "  SUPER+Shift+Q = quit dwm"
    echo "  SUPER+E       = thunar"
    echo "  SUPER+V       = toggle floating"
    echo "  SUPER+P       = rofi"
    echo "  SUPER+D       = fullscreen"
    echo "  SUPER+J/K     = focus next/prev"
    echo "  SUPER+H/L     = resize master"
    echo "  SUPER+1-9     = switch tag"
    echo "  SUPER+Shift+1-9 = move to tag"
  '';
}
