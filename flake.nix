{
  description = "flake for bootstrapping and running rsh shell";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};
  in {
    packages.${system}.rsh = pkgs.stdenv.mkDerivation {
      pname = "rsh";
      version = "0.0.0";

      src = ./.;

      nativeBuildInputs = with pkgs; [cmake gnumake gcc];

      buildInputs = with pkgs; [glibc ccls];

      # buildPhase = ''
      #   cmake -DCMAKE_BUILD_TYPE=Debug ..
      #           pwd
      #                   make
      # '';

      cmakeFlags = ["-DCMAKE_BUILD_TYPE=Debug"];

      dontStrip = true;
      installPhase = ''
        mkdir -p $out/bin
        cp rsh $out/bin
      '';

      shellHook = ''
        export libc_includes="${pkgs.clang}/nix-support"
      '';
    };

    defaultPackage.${system} = self.packages.${system}.rsh;

    devShells.${system}.default = pkgs.mkShell {
      buildInputs = with pkgs; [
        cmake
        gcc
        gnumake
        ccls
        bear
        gdb
        valgrind
      ];

      shellHook = ''
        echo "You're in the devShell for rsh project"
      '';
    };
  };
}
