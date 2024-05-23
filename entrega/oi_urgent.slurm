#!/bin/bash
#SBATCH --job-name=job_tagael
#SBATCH --nodes=2
#SBATCH --ntasks=2
#SBATCH --cpus-per-task=2
#SBATCH --partition=urgent
#SBATCH --mem=100M

echo Output do job $SLURM_JOB_ID
./teste
