pipeline {
    agent any
    stages {
        stage('Clean') {
            steps {
                sh 'rm -rf Demo-Project-for-Jenkins'
            }
        }
        stage('Checkout') {
            steps {
                sh 'git clone -b main https://github.com/bhoomikashirol/Demo-Project-for-Jenkins.git'
            }
        }
        stage('Verify Files') {
            steps {
                sh '''
                    echo "Contents of Demo-Project-for-Jenkins:"
                    ls -la Demo-Project-for-Jenkins
                    echo "Contents of Demo-Project-for-Jenkins/Code.cpp:"
                    cat Demo-Project-for-Jenkins/Code.cpp
                    echo "Contents of Demo-Project-for-Jenkins/CodeTest.cpp:"
                    cat Demo-Project-for-Jenkins/CodeTest.cpp
                '''
            }
        }
        stage('Build') {
            steps {
                sh '''
                    cd Demo-Project-for-Jenkins
                    mkdir -p build
                    cd build
                    cmake ..
                    make
                '''
            }
        }
        stage('Test') {
            steps {
                sh '''
                    cd Demo-Project-for-Jenkins/build
                    ./DemoTest
                '''
            }
        }
    }
}
