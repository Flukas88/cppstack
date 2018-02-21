# -*- coding: utf-8 -*-
# vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4
import subprocess
import unittest


class CppCalcTest(unittest.TestCase):

    def setUp(self):
        pass

    def test_valid_calc(self):
        out = subprocess.Popen(
            ["./cppstack", "5 1 2 + 4 x + 3 - 2 /"], stdout=subprocess.PIPE).communicate()[0]
        self.assertIn("7.000000", str(out))

    def test_invalid_calc(self):

        try:
            subprocess.Popen(
                ["./cppstack", "0 5 /"], stdout=subprocess.PIPE).communicate()[0]
        except e:
            pass


if __name__ == '__main__':
    unittest.main()
