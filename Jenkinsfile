pipeline {
    agent any

    stages {
        stage('---clean---') {
            steps {
                sh 'rm -rf build'
            }
        }

        stage('--build--') {
            steps {
                sh '''
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }

        stage('--test--') {
            steps {
                sh '''
                    cd build
                    ./DemoTest
                '''
            }
        }

        stage('--package--') {
            steps {
                sh '''
                    cd build
                    make package
                '''
            }
        }
    }
}
