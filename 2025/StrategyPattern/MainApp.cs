using System;
using System.Collections;

namespace DoFactory.GangOfFour.Strategy.RealWorld
{
    /// <summary>
    /// MainApp startup class for Real-World 
    /// Strategy Design Pattern.
    /// </summary>
    class MainApp
    {
        /// <summary>
        /// Entry point into console application.
        /// </summary>
        static void Main()
        {
            // Two contexts following different strategies
            SortedList studentRecords = new SortedList();

            studentRecords.Add("Samual");
            studentRecords.Add("Jimmy");
            studentRecords.Add("Sandra");
            studentRecords.Add("Vivek");
            studentRecords.Add("Anna");

            studentRecords.SetSortStrategy(new QuickSort());
            studentRecords.Sort();

            studentRecords.SetSortStrategy(new ShellSort());
            studentRecords.Sort();

            studentRecords.SetSortStrategy(new MergeSort());
            studentRecords.Sort();

            // Wait for user
            Console.Read();
        }
    }

    // "Strategy"

    abstract class SortStrategy
    {
        public abstract void Sort(ArrayList list);
    }

    // "ConcreteStrategy" 

    class QuickSort : SortStrategy
    {
        public override void Sort(ArrayList list)
        {
            list.Sort();  // Default is Quicksort
            Console.WriteLine("QuickSorted list ");
        }
    }

    // "ConcreteStrategy" 

    class ShellSort : SortStrategy
    {
        public override void Sort(ArrayList list)
        {
            int n = list.Count;
            
            // Start with a big gap, then reduce the gap
            for (int gap = n / 2; gap > 0; gap /= 2)
            {
                // Do a gapped insertion sort for this gap size.
                // The first gap elements list[0..gap-1] are already in gapped order
                // keep adding one more element until the entire list is gap sorted
                for (int i = gap; i < n; i += 1)
                {
                    // add list[i] to the elements that have been gap sorted
                    // save list[i] in temp and make a hole at position i
                    object temp = list[i];

                    // shift earlier gap-sorted elements up until the correct 
                    // location for list[i] is found
                    int j;
                    for (j = i; j >= gap && ((IComparable)list[j - gap]).CompareTo(temp) > 0; j -= gap)
                        list[j] = list[j - gap];

                    // put temp (the original list[i]) in its correct location
                    list[j] = temp;
                }
            }
            
            Console.WriteLine("ShellSorted list ");
        }
    }

    // "ConcreteStrategy" 

    class MergeSort : SortStrategy
    {
        public override void Sort(ArrayList list)
        {
            if (list.Count <= 1)
                return;

            MergeSortHelper(list, 0, list.Count - 1);
            Console.WriteLine("MergeSorted list ");
        }

        private void MergeSortHelper(ArrayList list, int left, int right)
        {
            if (left < right)
            {
                int mid = (left + right) / 2;

                MergeSortHelper(list, left, mid);
                MergeSortHelper(list, mid + 1, right);
                Merge(list, left, mid, right);
            }
        }

        private void Merge(ArrayList list, int left, int mid, int right)
        {
            ArrayList leftList = new ArrayList();
            ArrayList rightList = new ArrayList();

            for (int i = left; i <= mid; i++)
                leftList.Add(list[i]);

            for (int i = mid + 1; i <= right; i++)
                rightList.Add(list[i]);

            int leftIndex = 0;
            int rightIndex = 0;
            int mergedIndex = left;

            while (leftIndex < leftList.Count && rightIndex < rightList.Count)
            {
                if (((IComparable)leftList[leftIndex]).CompareTo(rightList[rightIndex]) <= 0)
                {
                    list[mergedIndex] = leftList[leftIndex];
                    leftIndex++;
                }
                else
                {
                    list[mergedIndex] = rightList[rightIndex];
                    rightIndex++;
                }
                mergedIndex++;
            }

            while (leftIndex < leftList.Count)
            {
                list[mergedIndex] = leftList[leftIndex];
                leftIndex++;
                mergedIndex++;
            }

            while (rightIndex < rightList.Count)
            {
                list[mergedIndex] = rightList[rightIndex];
                rightIndex++;
                mergedIndex++;
            }
        }
    }

    // "Context" 

    class SortedList
    {
        private ArrayList list = new ArrayList();
        private SortStrategy sortstrategy;

        public void SetSortStrategy(SortStrategy sortstrategy)
        {
            this.sortstrategy = sortstrategy;
        }

        public void Add(string name)
        {
            list.Add(name);
        }

        public void Sort()
        {
            sortstrategy.Sort(list);

            // Display results
            foreach (string name in list)
            {
                Console.WriteLine(" " + name);
            }
            Console.WriteLine();
        }
    }
}
