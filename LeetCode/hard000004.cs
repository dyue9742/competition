using System;

public class Solution {
	public double FindMedianSortedArrays(int[] nums1, int[] nums2) {
		int len = nums1.Length + nums2.Length;
		int[] mergedNums = new int[len];
		for (int i = 0; i < nums1.Length; i++)
			mergedNums[i] = nums1[i];
		for (int i = 0; i < nums2.Length; i++)
			mergedNums[i] = nums2[i];
		Array.Sort<int>(mergedNums, delegate(int m, int n) { return m - n; });

		double median = 0.0D;
		if (mergedNums.Length % 2 == 0) {
			double m1 = (double) mergedNums[mergedNums.Length / 2];
			double m2 = (double) mergedNums[mergedNums.Length / 2 - 1];
			median = (m1 + m2) / 2.0D;
		}
		else {
			median = (double) mergedNums[(mergedNums.Length - 1) / 2];
		}
		return median;
	}
}
