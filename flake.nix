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

      buildInputs = with pkgs; [gcc glibc ccls];

      installPhase = ''
        mkdir -p $out/bin
        cp rsh $out/bin
      '';

      shellHook = ''
        export libc_includes="${pkgs.clang}/nix-support"
      '';
    };

    defaultPackage.${system} = self.packages.${system}.rsh;
    # devShells.x86_64-linux.default = pkgs.mkShell {
    #   packages = [pkgs.expat];
    #
    #   shellHook = ''
    #     export C_INCLUDE_PATH=${pkgs.expat.dev}/include
    #   '';
    # };
  };
}
