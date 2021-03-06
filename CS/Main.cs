﻿/****************************************************************
 * Project: FormatString
 * File: Main.cs
 * Create Date: 2020/04/08
 * Author: Gao Jiongjiong
 * Descript: Variable parameter
****************************************************************/

using System;
class MainClass
{
    public static void Main(string[] args) {
        Print(1, 2, 3);
    }

    static void Print(params int[] args) {
        Console.Write("Print:");
        foreach(int arg in args) {
            Console.Write(" {0}", arg);
        }
        Console.WriteLine();
    }
}
