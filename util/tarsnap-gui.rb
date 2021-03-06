class TarsnapGui < Formula
  desc "Cross-platform GUI front-end for the Tarsnap command-line client."
  homepage "https://github.com/Tarsnap/tarsnap-gui/wiki/Tarsnap"
  url "https://github.com/Tarsnap/tarsnap-gui/archive/v1.0.tar.gz"
  sha256 "cd21d2a85f073e72f10900632fdcb49956985255a5711fb4f6d434433b09dac9"
  head "https://github.com/Tarsnap/tarsnap-gui.git"

  depends_on "qt"
  depends_on "tarsnap"

  def install
    system "qmake"
    system "make"
    system "macdeployqt", "Tarsnap.app"
    prefix.install "Tarsnap.app"
  end

  test do
    system "#{opt_prefix}/Tarsnap.app/Contents/MacOS/Tarsnap", "--version"
  end
end
