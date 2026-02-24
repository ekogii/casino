echo "Would you like to add '~/.local/bin' to your PATH environment variable?: [yn]"
echo -n "    -> "
read t

[[ $t == 'y' ]] && echo "export PATH='/home/$(whoami)/.local/bin:\$PATH'" >> ~/.bashrc

exit 0
