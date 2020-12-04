using System;
using System.IO;
using System.Linq;

namespace Day3
{
    class Program
    {
        const char TREE_SYMBOL = '#';

        static void Main(string[] args)
        {
            string[] lines = File.ReadAllLines(@"E:\fahri\Documents\GitHub\ProgrammingChallenges\AdventOfCode\2020\Day3\input");
            int patternLength = lines[0].Length;

            int[] yStepSizes = { 1, 1, 1, 1, 2 };
            int[] xStepSizes = { 1, 3, 5, 7, 1 };
            int[] numberTrees = new int[yStepSizes.Length];

            for (int i = 0; i < yStepSizes.Length; i++)
            {
                int xPosition = 0;
                for (int yPosition = 0; yPosition < lines.Length; yPosition += yStepSizes[i])
                {
                    if (lines[yPosition].ToCharArray()[xPosition] == TREE_SYMBOL)
                    {
                        numberTrees[i]++;
                    }

                    xPosition = (xPosition + xStepSizes[i]) % patternLength;
                }
            }


            Console.WriteLine($"Number Trees For Part 1: {numberTrees[1]}");
            Console.WriteLine();

            long treesMultiplied = 0;
            for (int i = 0; i < numberTrees.Length; i++)
            {
                Console.WriteLine($"Step Size X: {xStepSizes[i]}");
                Console.WriteLine($"Step Size Y: {yStepSizes[i]}");
                Console.WriteLine($"Number Trees: {numberTrees[i]}");
                Console.WriteLine();

                if (i == 0)
                    treesMultiplied += numberTrees[i];
                else
                    treesMultiplied *= numberTrees[i];
            }
            Console.WriteLine($"Trees multiplied: {treesMultiplied}");
        }
    }
}
