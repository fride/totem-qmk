{ pkgs ? import <nixpkgs> {} }:
with pkgs;
mkShell {
  buildInputs = [
    git
    kondo
    babashka
    clj-kondo
  ];
}