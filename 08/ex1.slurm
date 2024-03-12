#!/bin/bash
#SBATCH --job-name=knapsack_08_ex1
#SBATCH --output=ex1_out.txt
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1
#SBATCH --mem=100K

echo Output do job $SLURM_JOB_ID
export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK
./ex1
