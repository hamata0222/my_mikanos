# USBマウスが動かない件について

ホストコントローラ（xHC）のベンダーIDがNEC（0x1033）になっていた。
Intel製のxHC用にEHCIをxHCIに変更したように、NEC製のxHCもこの処理が必要なのでは。
`main.cpp`では、`SwitchEhci2Xhci()`を呼び出すのは、Intel製の場合のみ。

`SwitchEhci2Xhci()`では、Intel製のEHCIに限定して、PCIコンフィギュレーション空間を操作してEHCIをxHCIに変更しているっぽい。

解決した。
QEMUのウィンドウをアクティブにしていないだけだった。ウィンドウだけがアクティブになっていても、マウスで一回クリックしないと認識されないみたい。


# QEMUのxHCについて

何か設定でホストコントローラーを追加したりできるのか？

# ホスト側のUSBデバイスについて

Win10の方のデバイスマネージャーでは、Intel製のxHCが表示されている。
QEMUにとってホストはUbuntuなので、UbuntuのxHCがどうなっているかを確認すればよいのか？

ちょっと調べた限り、WSL2でUSBデバイス等のPCIデバイスを直接見る方法がないっぽい。
マウス等の入力はWindowsが処理しているのか？

# csとssで3bitずらしている理由

レジスタの構造で、セグメントのindexを設定するのがbit3以降だから。

[参考資料]{https://babyron64.hatenablog.com/entry/2017/12/22/210124}

# C++のイテレータについて

``Layer.cpp``の``FindLayer()``にある``std::find_if()``での使われ方がよくわからない。
``layers_.begin()``と``layers_.end()``は、イテレータらしい。
イテレータを比較する文が出てくるけど、イテレータを比較するってどういうこと？

# WindowクラスのDrawTo()にwriterを渡す必要があるのか

Windowクラスはメンバ変数としてwriterを持っているのに、DrawTo()で外部のwriterに対してWindowの内容を描画することがるのか？
