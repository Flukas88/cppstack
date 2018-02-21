# -*- coding: utf-8 -*-
# vim: tabstop=8 expandtab shiftwidth=4 softtabstop=4
import subprocess 
import unittest


class CppCalcTest(unittest.TestCase):
    def setUp(self):
        pass

    def test_valid_calc(self): 
        self.assertIn("6",subprocess.check_output(['../cppstack', '"5 1 2 + 4 x + 3 - 2 /"']))

    def test_invalid_calc(self):
        self.assertIn("possible", subprocess.check_output(['../cppstack', '"5 5 /"']))

if __name__ == '__main__':
    unittest.main()


